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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "culling_of_stratholme.h"
#include "InstanceScript.h"
#include "MotionMaster.h"

enum Spells
{
    SPELL_CORRUPTING_BLIGHT                     = 60588,
    SPELL_VOID_STRIKE                           = 60590,
    SPELL_CORRUPTION_OF_TIME_AURA               = 60451,
    SPELL_CORRUPTION_OF_TIME_CHANNEL            = 60422,
    SPELL_CHANNEL_VISUAL                        = 31387
};

enum Events
{
    EVENT_SPELL_CORRUPTING_BLIGHT               = 1,
    EVENT_SPELL_VOID_STRIKE                     = 2,
    EVENT_SPELL_CHANNEL_VISUAL                  = 3,
    EVENT_SPELL_CORRUPTION_OF_TIME_CHANNEL      = 4
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_DEATH                                   = 1,
    SAY_FAIL                                    = 2
};

enum Misc
{
    SAY_SUCCESS                                 = 0,

    MOVEMENT_TIME_RIFT                          = 1
};

struct boss_infinite_corruptor : public BossAI
{
    boss_infinite_corruptor(Creature* creature) : BossAI(creature, DATA_SHOW_INFINITE_TIMER)
    {
        events.ScheduleEvent(EVENT_SPELL_CHANNEL_VISUAL, 0s);
    }

    uint32 beamTimer;
    ObjectGuid TimeRiftGUID;
    ObjectGuid GuardianGUID;

    void Reset() override
    {
        _Reset();

        if (getTimeRift() && getGuardian())
        {
            getTimeRift()->DespawnOrUnsummon();
            getGuardian()->DespawnOrUnsummon();
        }

        if (instance->GetData(DATA_GUARDIANTIME_EVENT) == NOT_STARTED)
            me->DespawnOrUnsummon(5ms, 0s);

        if (Creature* TimeRift = me->SummonCreature(NPC_TIME_RIFT, 2337.6f, 1270.0f, 132.95f, 2.79f))
            TimeRiftGUID = TimeRift->GetGUID();

        if (Creature* Guardian = me->SummonCreature(NPC_GUARDIAN_OF_TIME, 2319.3f, 1267.7f, 132.8f, 1.0f))
            GuardianGUID = Guardian->GetGUID();

        beamTimer = 1;
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_CORRUPTION_OF_TIME_CHANNEL)
            target->CastSpell(target, SPELL_CORRUPTION_OF_TIME_AURA, true);
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);
        me->InterruptNonMeleeSpells(false);
        events.ScheduleEvent(EVENT_SPELL_VOID_STRIKE, 8s);
        events.ScheduleEvent(EVENT_SPELL_CORRUPTING_BLIGHT, 12s);
        Talk(SAY_AGGRO);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (me->HasReactState(REACT_PASSIVE))
            return;
        BossAI::EnterEvadeMode(why);
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_DEATH);

        if (getGuardian() && getTimeRift())
        {
            getGuardian()->SetFacingToObject(killer);
            getGuardian()->DespawnOrUnsummon(15s, 0s);
            getGuardian()->RemoveAllAuras();
            getGuardian()->AI()->Talk(SAY_SUCCESS);
            getTimeRift()->DespawnOrUnsummon(1s, 0s);
        }

        instance->SetData(DATA_SHOW_INFINITE_TIMER, NOT_STARTED);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CORRUPTING_BLIGHT);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == MOVEMENT_TIME_RIFT)
        {
            me->DespawnOrUnsummon(5s, 0s);
            instance->SetBossState(DATA_SHOW_INFINITE_TIMER, FAIL);
        }
    }

    void DoAction(int32 param) override
    {
        if (!me->IsAlive())
            return;

        if (param == ACTION_RUN_OUT_OF_TIME)
        {
            Talk(SAY_FAIL);

            if (getTimeRift() && getGuardian())
            {
                getGuardian()->DespawnOrUnsummon();
                getTimeRift()->DespawnOrUnsummon(8s, 0s);

                if (me->IsWithinDist2d(getTimeRift(), 5.0f))
                    MovementInform(POINT_MOTION_TYPE, MOVEMENT_TIME_RIFT);
                else
                    me->GetMotionMaster()->MovePoint(MOVEMENT_TIME_RIFT, getTimeRift()->GetPosition()); // @todo offset
            }
            else
                MovementInform(POINT_MOTION_TYPE, MOVEMENT_TIME_RIFT);
        }
    }

    Creature* getTimeRift() { return ObjectAccessor::GetCreature(*me, TimeRiftGUID); }
    Creature* getGuardian() { return ObjectAccessor::GetCreature(*me, GuardianGUID); }

    void UpdateAI(uint32 diff) override
    {
        if (beamTimer)
        {
            beamTimer += diff;
            if (beamTimer >= 2000)
            {
                me->CastSpell(me, SPELL_CORRUPTION_OF_TIME_CHANNEL, true);
                beamTimer = 0;
            }
        }

        if (UpdateVictim())
        {
            // Spell Channel Visual
            me->InterruptNonMeleeSpells(false);
            DoMeleeAttackIfReady();
        }

        events.Update(diff);

        switch (events.ExecuteEvent())
        {
            case EVENT_SPELL_VOID_STRIKE:
                DoCastVictim(SPELL_VOID_STRIKE);
                events.RepeatEvent(8000);
                break;
            case EVENT_SPELL_CORRUPTING_BLIGHT:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, true))
                    DoCast(target, SPELL_CORRUPTING_BLIGHT);
                events.RepeatEvent(12000);
                break;
            case EVENT_SPELL_CHANNEL_VISUAL:
                if (getGuardian())
                    me->CastSpell(getGuardian(), SPELL_CHANNEL_VISUAL, true);
                break;
        }
    }
};

void AddSC_boss_infinite_corruptor()
{
    RegisterCullingOfStratholmeCreatureAI(boss_infinite_corruptor);
}
