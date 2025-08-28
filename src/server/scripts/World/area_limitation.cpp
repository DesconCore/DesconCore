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

#include "ScriptMgr.h"
#include "CreatureTextMgr.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "area_limitation.h"

class spell_wyrmrest_defender_mount : public AuraScript
{
public:
    PrepareAuraScript(spell_wyrmrest_defender_mount);

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARNING_WYRMREST });
    }

    bool AreaCheck(Unit* target)
    {
        return target && RestrictedAreasWyrmrestDefenderMount.count(target->GetAreaId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (RestrictedAreasWyrmrestDefenderMount.count(owner->GetAreaId()))
            owner->RemoveAura(SPELL_WARNING_WYRMREST);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* wyrmrest = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(wyrmrest, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_WARNING_WYRMREST, true);
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_wyrmrest_defender_mount::AreaCheck);
        OnEffectApply += AuraEffectApplyFn(spell_wyrmrest_defender_mount::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_wyrmrest_defender_mount::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_wintergarde_gryphon_commander : public AuraScript
{
public:
    PrepareAuraScript(spell_wintergarde_gryphon_commander);

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARNING_GRYPHON });
    }

    bool CheckArea(Unit* target)
    {
        return target && RestrictedAreasWintergardeGryphonCommander.count(target->GetAreaId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (RestrictedAreasWintergardeGryphonCommander.count(owner->GetAreaId()))
            owner->RemoveAura(SPELL_WARNING_GRYPHON);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* gryphon = GetCaster()->GetVehicleCreatureBase())
        {
            Player* target = GetUnitOwner()->ToPlayer();
            sCreatureTextMgr->SendChat(gryphon, TEXT_EMOTE, GetUnitOwner(), CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            GetUnitOwner()->CastSpell(GetUnitOwner(), SPELL_WARNING_GRYPHON, true);
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_wintergarde_gryphon_commander::CheckArea);
        OnEffectApply += AuraEffectApplyFn(spell_wintergarde_gryphon_commander::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_wintergarde_gryphon_commander::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ride_flamebringer : public AuraScript
{
public:
    PrepareAuraScript(spell_ride_flamebringer);

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARNING_FLAMEBRINGER });
    }

    bool CheckArea(Unit* target)
    {
        return target && target->GetAreaId() != RestrictedAreaFlamebringer;
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* flamebringer = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(flamebringer, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_WARNING_FLAMEBRINGER, true);
        }
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (owner->GetAreaId() == RestrictedAreaFlamebringer)
            owner->RemoveAura(SPELL_WARNING_FLAMEBRINGER);
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_ride_flamebringer::CheckArea);
        OnEffectApply += AuraEffectApplyFn(spell_ride_flamebringer::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_ride_flamebringer::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_bone_gryphon : public AuraScript
{
public:
    PrepareAuraScript(spell_bone_gryphon);

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool CheckArea(Unit* target)
    {
        return target && target->GetAreaId() == RestrictedAreaOnslaughtHarbor;
    }

    bool Load() override
    {
        Unit* owner = GetUnitOwner();
        return owner && owner->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (owner->GetAreaId() == RestrictedAreaOnslaughtHarbor)
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* gryphon = owner->GetVehicleCreatureBase())
        {
            Player* target = GetUnitOwner()->ToPlayer();
            sCreatureTextMgr->SendChat(gryphon, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_bone_gryphon::CheckArea);
        OnEffectApply += AuraEffectApplyFn(spell_bone_gryphon::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_bone_gryphon::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_onslaught_gryphon : public AuraScript
{
public:
    PrepareAuraScript(spell_onslaught_gryphon);

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool CheckZone(Unit* target)
    {
        return target && target->GetZoneId() == RestrictedZoneOnslaughtGryphon;
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (owner->GetZoneId() == RestrictedZoneOnslaughtGryphon)
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* gryphon = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(gryphon, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_onslaught_gryphon::CheckZone);
        OnEffectApply += AuraEffectApplyFn(spell_onslaught_gryphon::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_onslaught_gryphon::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ride_freed_proto_drake : public AuraScript
{
public:
    PrepareAuraScript(spell_ride_freed_proto_drake);

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING_2 });
    }

    bool AreaCheck(Unit* target)
    {
        return target && !RestrictedAreasRideFreedProtoDrake.contains(target->GetAreaId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* drake = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(drake, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING_2, true);
        }
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (RestrictedAreasRideFreedProtoDrake.count(owner->GetAreaId()))
            owner->RemoveAura(SPELL_BOUNDARY_WARNING_2);
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_ride_freed_proto_drake::AreaCheck);
        OnEffectApply += AuraEffectApplyFn(spell_ride_freed_proto_drake::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_ride_freed_proto_drake::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_command_argent_skytalon : public AuraScript
{
public:
    PrepareAuraScript(spell_command_argent_skytalon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target && RestrictedAreasArgentSkytalon.contains(target->GetAreaId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (RestrictedAreasArgentSkytalon.count(owner->GetAreaId()))
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (Creature* skytalon = owner->GetVehicleCreatureBase())
        {
            if (Player* player = owner->ToPlayer())
            {
                sCreatureTextMgr->SendChat(skytalon, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, player);
                owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
            }
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_command_argent_skytalon::AreaCheck);
        OnEffectApply += AuraEffectApplyFn(spell_command_argent_skytalon::HandleApply, EFFECT_1, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_command_argent_skytalon::HandleRemove, EFFECT_1, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_wyrmrest_commander : public AuraScript
{
public:
    PrepareAuraScript(spell_wyrmrest_commander);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target && RestrictedAreasWyrmrestCommander.contains(target->GetAreaId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (RestrictedAreasWyrmrestCommander.count(owner->GetAreaId()))
            owner->RemoveAurasDueToSpell(SPELL_BOUNDARY_WARNING);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (Creature* wyrmrest = owner->GetVehicleCreatureBase())
        {
            if (Player* player = owner->ToPlayer())
            {
                sCreatureTextMgr->SendChat(wyrmrest, TEXT_WYRMREST, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, player);
                owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
            }
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_wyrmrest_commander::AreaCheck);
        OnEffectApply += AuraEffectApplyFn(spell_wyrmrest_commander::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_wyrmrest_commander::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_korkron_wing_commander : public AuraScript
{
public:
    PrepareAuraScript(spell_korkron_wing_commander);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target && RestrictedAreaKorkronWingCommander.contains(target->GetAreaId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (RestrictedAreaKorkronWingCommander.count(owner->GetAreaId()))
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (Creature* korkron = owner->GetVehicleCreatureBase())
        {
            if (Player* player = owner->ToPlayer())
            {
                sCreatureTextMgr->SendChat(korkron, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, player);
                owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
            }
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_korkron_wing_commander::AreaCheck);
        OnEffectApply += AuraEffectApplyFn(spell_korkron_wing_commander::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_korkron_wing_commander::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_frostbrood_vanquisher : public AuraScript
{
public:
    PrepareAuraScript(spell_frostbrood_vanquisher);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target && RestrictedAreaFrostbroodVanquisher.contains(target->GetAreaId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (RestrictedAreaFrostbroodVanquisher.count(owner->GetAreaId()))
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (!owner->GetVehicleCreatureBase())
            owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (Creature* vanquisher = owner->GetVehicleCreatureBase())
        {
            if (Player* player = owner->ToPlayer())
            {
                sCreatureTextMgr->SendChat(vanquisher, TEXT_FROSTBROOD, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, player);
                owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
            }
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_frostbrood_vanquisher::AreaCheck);
        OnEffectApply += AuraEffectApplyFn(spell_frostbrood_vanquisher::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_frostbrood_vanquisher::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_ride_vehicle_hardcoded : public AuraScript
{
public:
    PrepareAuraScript(spell_ride_vehicle_hardcoded);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING_3 });
    }

    bool CheckArea(Unit* target)
    {
        return target && !RestrictedAreasRideVehicleHardcoded.count(target->GetAreaId());
    }

    bool CheckZone(Unit* target)
    {
        return target && !RestrictedZonesRideVehicleHardcoded.count(target->GetZoneId());
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (Creature* vehicle = owner->GetVehicleCreatureBase())
        {
            if (Player* player = owner->ToPlayer())
            {
                sCreatureTextMgr->SendChat(vehicle, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, player);
                owner->CastSpell(owner, SPELL_BOUNDARY_WARNING_3, true);
            }
        }
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        const uint32 areaId = owner->GetAreaId();
        const uint32 zoneId = owner->GetZoneId();

        if (RestrictedAreasRideVehicleHardcoded.count(areaId) || RestrictedZonesRideVehicleHardcoded.count(zoneId))
        {
            owner->RemoveAura(SPELL_BOUNDARY_WARNING_3);
        }
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_ride_vehicle_hardcoded::CheckArea);
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_ride_vehicle_hardcoded::CheckZone);
        OnEffectApply += AuraEffectApplyFn(spell_ride_vehicle_hardcoded::HandleApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_ride_vehicle_hardcoded::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_area_limitation()
{
    RegisterSpellScript(spell_wyrmrest_defender_mount);
    RegisterSpellScript(spell_wintergarde_gryphon_commander);
    RegisterSpellScript(spell_ride_flamebringer);
    RegisterSpellScript(spell_bone_gryphon);
    RegisterSpellScript(spell_onslaught_gryphon);
    RegisterSpellScript(spell_ride_freed_proto_drake);
    RegisterSpellScript(spell_command_argent_skytalon);
    RegisterSpellScript(spell_wyrmrest_commander);
    RegisterSpellScript(spell_korkron_wing_commander);
    RegisterSpellScript(spell_frostbrood_vanquisher);
    RegisterSpellScript(spell_ride_vehicle_hardcoded);
}
