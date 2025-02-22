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

void AddSC_check_generic_spell_scripts()
{
    RegisterSpellScript(spell_gen_select_target_dead);
    RegisterSpellScript(spell_gen_target_is_in_combat);
    RegisterSpellScript(spell_summon_raven_god);
}
