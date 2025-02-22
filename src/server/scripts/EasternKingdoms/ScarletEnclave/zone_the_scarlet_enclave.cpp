/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CreatureScript.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include <SpellScriptLoader.h>
#include <CreatureTextMgr.h>

/*####
## npc_valkyr_battle_maiden
####*/

enum Spells_VBM
{
    SPELL_REVIVE                = 51918
};

enum Says_VBM
{
    WHISPER_REVIVE              = 0
};

class npc_valkyr_battle_maiden : public CreatureScript
{
public:
    npc_valkyr_battle_maiden() : CreatureScript("npc_valkyr_battle_maiden") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_valkyr_battle_maidenAI(creature);
    }

    struct npc_valkyr_battle_maidenAI : public PassiveAI
    {
        npc_valkyr_battle_maidenAI(Creature* creature) : PassiveAI(creature) { }

        uint32 FlyBackTimer;
        float x, y, z;
        uint32 phase;

        void Reset() override
        {
            me->setActive(true);
            me->SetVisible(false);
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetCanFly(true);
            FlyBackTimer = 500;
            phase = 0;

            me->GetPosition(x, y, z);
            z += 4.0f;
            x -= 3.5f;
            y -= 5.0f;
            me->GetMotionMaster()->Clear(false);
            me->SetPosition(x, y, z, 0.0f);
        }

        void UpdateAI(uint32 diff) override
        {
            if (FlyBackTimer <= diff)
            {
                Player* player = nullptr;
                if (me->IsSummon())
                {
                    if (Unit * summoner = me->ToTempSummon()->GetSummonerUnit())
                    {
                        player = summoner->ToPlayer();
                    }
                }

                if (!player)
                {
                    phase = 3;
                }

                switch (phase)
                {
                    case 0:
                        me->SetWalk(false);
                        me->HandleEmoteCommand(EMOTE_STATE_FLYGRABCLOSED);
                        FlyBackTimer = 500;
                        break;
                    case 1:
                        if (player)
                        {
                            player->GetClosePoint(x, y, z, me->GetObjectSize());
                        }
                        z += 2.5f;
                        x -= 2.0f;
                        y -= 1.5f;
                        me->GetMotionMaster()->MovePoint(0, x, y, z);
                        if (player)
                        {
                            me->SetTarget(player->GetGUID());
                        }
                        me->SetVisible(true);
                        FlyBackTimer = 4500;
                        break;
                    case 2:
                        if (player && !player->isResurrectRequested())
                        {
                            me->HandleEmoteCommand(EMOTE_ONESHOT_CUSTOM_SPELL_01);
                            DoCast(player, SPELL_REVIVE, true);
                            Talk(WHISPER_REVIVE, player);
                        }
                        FlyBackTimer = 5000;
                        break;
                    case 3:
                        me->SetVisible(false);
                        FlyBackTimer = 3000;
                        break;
                    case 4:
                        me->DisappearAndDie();
                        break;
                    default:
                        //Nothing To DO
                        break;
                }
                ++phase;
            }
            else FlyBackTimer -= diff;
        }
    };
};

enum QuestAnEndToAllThings
{
    SPELL_BOUNDARY_WARNING          = 51272,
    SPELL_DEVOUR_HUMANOID           = 53110,
    SPELL_DEVOUR_CONTROL_VEHICLE    = 53111,

    SAY_CRUSADER_AGGRO              = 0,

    EVENT_TAKE_OFF                  = 1,

    POINT_TAKE_OFF                  = 1,

    NPC_HEARTHGLEN_CRUSADER         = 29102,
    NPC_TIRISFAL_CRUSADER           = 29103
};

class npc_frostbrood_vanquisher : public VehicleAI
{
public:
    npc_frostbrood_vanquisher(Creature* creature) : VehicleAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(3s, 0s);
    }

    void TakeJump(Unit* passenger)
    {
        Position pos = me->GetPosition();
        pos.m_positionY -= 10.0f;
        pos.m_positionZ += 8.0f;
        me->SetPosition(pos);
        passenger->SetSpeedRate(MOVE_RUN, 5.0f);
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
    {
        // Only apply the skill Devour Humanoid
        if (!apply && seatId == 0)
        {
            if (Vehicle* frostbrood = me->GetVehicleKit())
            {
                if (Unit* crusader = frostbrood->GetPassenger(1))
                {
                    if (!crusader->IsCreature())
                        return;
                }
            }

            events.ScheduleEvent(EVENT_TAKE_OFF, 0s);
            me->CastSpell(passenger, VEHICLE_SPELL_PARACHUTE, true);
            passenger->RemoveAurasDueToSpell(SPELL_BOUNDARY_WARNING);
            TakeJump(passenger);
            RemoveVehicleFlag();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TAKE_OFF:
                {
                    me->DespawnOrUnsummon(4050);
                    me->SetCanFly(true);
                    me->SetOrientation(2.5f);
                    me->SetSpeedRate(MOVE_FLIGHT, 1.0f);
                    me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
                    Position pos = me->GetPosition();
                    Position offset = { 14.0f, 14.0f, 16.0f, 0.0f };
                    pos.RelocateOffset(offset);
                    me->GetMotionMaster()->MovePoint(POINT_TAKE_OFF, pos);
                    break;
                }
            }
        }
    }
};

class spell_devour_humanoid : public SpellScript
{
    PrepareSpellScript(spell_devour_humanoid);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DEVOUR_CONTROL_VEHICLE });
    }

    SpellCastResult CheckRequirement()
    {
        if (!GetCaster()->HasAura(SPELL_DEVOUR_CONTROL_VEHICLE))
            return SPELL_CAST_OK;
        return SPELL_FAILED_DONT_REPORT;
    }

    SpellCastResult CheckCast()
    {
        uint32 cEntry[2] = { NPC_HEARTHGLEN_CRUSADER, NPC_TIRISFAL_CRUSADER };
        for (uint8 i = 0; i < 2; i++)
            if (GetCaster()->FindNearestCreature(cEntry[i], 15.0f, true))
                return SPELL_CAST_OK;
        return SPELL_FAILED_OUT_OF_RANGE;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_devour_humanoid::CheckRequirement);
        OnCheckCast += SpellCheckCastFn(spell_devour_humanoid::CheckCast);
    }
};

struct npc_crusader : public ArcherAI
{
public:
    npc_crusader(Creature* creature) : ArcherAI(creature) { }

    void Reset() override
    {
        me->RemoveUnitFlag(UNIT_FLAG_STUNNED);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_CRUSADER_AGGRO);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_DEVOUR_HUMANOID)
        {
            me->CombatStop(true);
            me->SetUnitFlag(UNIT_FLAG_STUNNED);
        }
    }
};

enum Frostbrood
{
    SAY_0 = 0
};

class spell_12779_call_of_the_frostbrood : public SpellScript
{
    PrepareSpellScript(spell_12779_call_of_the_frostbrood);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        uint32 entry = uint32(GetSpellInfo()->Effects[effIndex].MiscValue);
        uint32 spellId = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
        Unit* caster = GetCaster();
        Position pos = caster->GetPosition();
        pos.m_positionZ += 5.0f;
        Player* player = caster->ToPlayer();

        if (Creature* frostbrood = caster->SummonCreature(entry, pos))
        {
            caster->CastSpell(frostbrood, spellId, true);
            sCreatureTextMgr->SendChat(frostbrood, SAY_0, player, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, player);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_12779_call_of_the_frostbrood::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

void AddSC_the_scarlet_enclave()
{
    new npc_valkyr_battle_maiden();
    RegisterCreatureAI(npc_frostbrood_vanquisher);
    RegisterSpellScript(spell_devour_humanoid);
    RegisterCreatureAI(npc_crusader);
    RegisterSpellScript(spell_12779_call_of_the_frostbrood);
}
