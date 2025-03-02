/*
 * This file is part of the DesconCore Project. See AUTHORS file for Copyright information
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

#include "SpellScript.h"
#include "SpellScriptLoader.h"

class spell_gen_select_target_dead : public SpellScript
{
    PrepareSpellScript(spell_gen_select_target_dead);

    SpellCastResult CheckRequirement()
    {
        if (Unit* target = GetExplTargetUnit())
            if (!target->IsAlive())
                return SPELL_CAST_OK;

        return SPELL_FAILED_TARGET_NOT_DEAD;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_select_target_dead::CheckRequirement);
    }
};

class spell_gen_target_is_in_combat : public SpellScript
{
    PrepareSpellScript(spell_gen_target_is_in_combat);

    SpellCastResult CheckRequirement()
    {
        if (Unit* target = GetExplTargetUnit())
            if (!target->IsInCombat())
                return SPELL_CAST_OK;

        return SPELL_FAILED_TARGET_IN_COMBAT;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_gen_target_is_in_combat::CheckRequirement);
    }
};

enum Raven
{
    NPC_INVIS_RAVEN_GOD_PORTA    = 23046,
    SPELL_SUMMON_RAVEN_GOD       = 40098,
    GO_THE_SAGA_OF_TEROKK        = 183050
};

class spell_summon_raven_god : public SpellScript
{
public:
    PrepareSpellScript(spell_summon_raven_god);

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_RAVEN_GOD });
    }

    SpellCastResult CheckRequirement()
    {
        if (Creature* bird = GetCaster()->FindNearestCreature(NPC_INVIS_RAVEN_GOD_PORTA, 50.0f))
            if (!bird->HasAura(SPELL_SUMMON_RAVEN_GOD))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_summon_raven_god::CheckRequirement);
    }
};

class spell_dream_vision : public SpellScript
{
    PrepareSpellScript(spell_dream_vision);

    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        Unit* caster = GetCaster();
        uint32 entry = uint32(GetSpellInfo()->Effects[effIndex].MiscValue);
        SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->Effects[effIndex].MiscValueB));
        uint32 duration = uint32(GetSpellInfo()->GetDuration());

        Position pos = caster->GetPosition();
        if (Creature* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id))
        {
            summon->SetHover(true);
            summon->SetWaterWalking(true);
            summon->SetFeatherFall(true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_dream_vision::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

class spell_dream_vision_aura : public AuraScript
{
    PrepareAuraScript(spell_dream_vision_aura);

    void HandleAuraApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        PreventDefaultAction();
        if (Player* player = GetTarget()->ToPlayer())
        {
            player->UnsummonPetTemporaryIfAny();
        }
    }

    void HandleAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetTarget()->ToPlayer())
        {
            if (Unit* charm = player->GetCharm())
                charm->ToTempSummon()->UnSummon();

            player->ResummonPetTemporaryUnSummonedIfAny();
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_dream_vision_aura::HandleAuraApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dream_vision_aura::HandleAuraRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_check_generic_spell_scripts()
{
    RegisterSpellScript(spell_gen_select_target_dead);
    RegisterSpellScript(spell_gen_target_is_in_combat);
    RegisterSpellScript(spell_summon_raven_god);
    RegisterSpellAndAuraScriptPair(spell_dream_vision, spell_dream_vision_aura);
}
