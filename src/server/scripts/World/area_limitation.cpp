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

enum Texts
{
    TEXT_EMOTE                               = 0,
    TEXT_FROSTBROOD                          = 1,
    TEXT_WYRMREST                            = 3
};

enum Spells
{
    SPELL_WARNING_WYRMREST                   = 50065,
    SPELL_WARNING_GRYPHON                    = 48366,
    SPELL_WARNING_FLAMEBRINGER               = 48694,
    SPELL_BOUNDARY_WARNING                   = 51272,
    SPELL_BOUNDARY_WARNING_2                 = 51259,
    SPELL_BOUNDARY_WARNING_3                 = 56966
};

enum Ground
{
    ONSLAUGHT_HARBOR                         = 4417,
    VOLDRUNE                                 = 4207,
    WINTERGARDE_KEEP                         = 4177,
    WINTERGARDE_MINE                         = 4178,
    THE_CARRION_FIELDS                       = 4188,
    THE_DRAGON_WASTES                        = 4254,
    PATH_OF_THE_TITANS                       = 4184,
    AZURE_DRAGONSHRINE                       = 4183,
    THE_MIRROR_OF_DAWN                       = 4176,
    WYRMREST_TEMPLE                          = 4161,
    DUN_NIFFELEM                             = 4438,
    VALLEY_OF_ANCIENT_WINTERS                = 4437,
    BRUNNHILDAR_VILLAGE                      = 4422,
    THE_PIT_OF_THE_FANG                      = 4535,
    THE_ARGENT_VANGUARD                      = 4501,
    VALLEY_OF_ECHOES                         = 4504,
    THE_BREACH                               = 4505,
    SCOURGEHOLME                             = 4506,
    GALAKRONDS_REST                          = 4173,
    THE_WICKED_COIL                          = 4174,
    ICEMIST_VILLAGE                          = 4163,
    DEATHS_BREACH                            = 4356,
    HAVENSHIRE                               = 4347,
    HAVENSHIRE_STABLES                       = 4350,
    HAVENSHIRE_LUMBER_MIL                    = 4349,
    HAVENSHIRE_FARMS                         = 4348,
    CRYPT_OF_REMEMBRANCE                     = 4355,
    NEW_AVALON                               = 4343,
    NEW_AVALON_FORGE                         = 4377,
    THE_SHADOW_VAULT                         = 4477,
    WEEPING_QUARRY                           = 4517

};

enum Zone
{
    ICECROWN                                 = 210,
    SHOLAZAR_BASIN                           = 3711,
    THE_STORM_PEAKS                          = 67,
    ICECROWN_CIDADEL                         = 4812
};

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
        return target->GetAreaId() == THE_DRAGON_WASTES || target->GetAreaId() == PATH_OF_THE_TITANS || target->GetAreaId() == AZURE_DRAGONSHRINE ||
               target->GetAreaId() == THE_MIRROR_OF_DAWN || target->GetAreaId() == WYRMREST_TEMPLE;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        switch (owner->GetAreaId())
        {
            case THE_DRAGON_WASTES:
            case PATH_OF_THE_TITANS:
            case AZURE_DRAGONSHRINE:
            case THE_MIRROR_OF_DAWN:
            case WYRMREST_TEMPLE:
                owner->RemoveAura(SPELL_WARNING_WYRMREST);
                break;
        }

        if (owner->GetVehicleCreatureBase())
            return;

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
        return target->GetAreaId() == WINTERGARDE_KEEP || target->GetAreaId() == WINTERGARDE_MINE || target->GetAreaId() == THE_CARRION_FIELDS;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        switch (owner->GetAreaId())
        {
            case WINTERGARDE_KEEP:
            case WINTERGARDE_MINE:
            case THE_CARRION_FIELDS:
                owner->RemoveAura(SPELL_WARNING_GRYPHON);
                break;
        }

        if (owner->GetVehicleCreatureBase())
            return;

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
        return target->GetAreaId() != VOLDRUNE;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
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
        if (owner->GetAreaId() == VOLDRUNE)
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
        return target->GetAreaId() == ONSLAUGHT_HARBOR;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (owner->GetAreaId() == ONSLAUGHT_HARBOR)
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (owner->GetVehicleCreatureBase())
            return;

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
        return target->GetZoneId() == ICECROWN;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (owner->GetZoneId() == ICECROWN)
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (owner->GetVehicleCreatureBase())
            return;

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
        return target->GetAreaId() != DUN_NIFFELEM && target->GetAreaId() != VALLEY_OF_ANCIENT_WINTERS && target->GetAreaId() != BRUNNHILDAR_VILLAGE &&
               target->GetAreaId() != THE_PIT_OF_THE_FANG;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
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
        switch (owner->GetAreaId())
        {
            case DUN_NIFFELEM:
            case VALLEY_OF_ANCIENT_WINTERS:
            case BRUNNHILDAR_VILLAGE:
            case THE_PIT_OF_THE_FANG:
                owner->RemoveAura(SPELL_BOUNDARY_WARNING_2);
                break;
        }
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

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target->GetAreaId() == THE_ARGENT_VANGUARD || target->GetAreaId() == VALLEY_OF_ECHOES || target->GetAreaId() == THE_BREACH ||
               target->GetAreaId() == SCOURGEHOLME;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        switch (owner->GetAreaId())
        {
            case THE_ARGENT_VANGUARD:
            case VALLEY_OF_ECHOES:
            case THE_BREACH:
            case SCOURGEHOLME:
                owner->RemoveAura(SPELL_BOUNDARY_WARNING);
                break;
        }

        if (owner->GetVehicleCreatureBase())
            return;

        owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* sytalon = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(sytalon, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
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

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target->GetAreaId() == WYRMREST_TEMPLE || target->GetAreaId() == THE_DRAGON_WASTES || target->GetAreaId() == GALAKRONDS_REST ||
               target->GetAreaId() == THE_WICKED_COIL || target->GetAreaId() == PATH_OF_THE_TITANS;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        switch (owner->GetAreaId())
        {
            case WYRMREST_TEMPLE:
            case THE_DRAGON_WASTES:
            case GALAKRONDS_REST:
            case THE_WICKED_COIL:
            case PATH_OF_THE_TITANS:
                owner->RemoveAurasDueToSpell(SPELL_BOUNDARY_WARNING);
                break;
        }

        if (owner->GetVehicleCreatureBase())
            return;

        owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* wyrmrest = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(wyrmrest, TEXT_WYRMREST, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
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

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target->GetAreaId() == ICEMIST_VILLAGE;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        if (owner->GetAreaId() == ICEMIST_VILLAGE)
            owner->RemoveAura(SPELL_BOUNDARY_WARNING);

        if (owner->GetVehicleCreatureBase())
            return;

        owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* korkron = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(korkron, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
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

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING });
    }

    bool AreaCheck(Unit* target)
    {
        return target->GetAreaId() == DEATHS_BREACH || target->GetAreaId() == HAVENSHIRE || target->GetAreaId() == HAVENSHIRE_STABLES ||
               target->GetAreaId() == HAVENSHIRE_LUMBER_MIL || target->GetAreaId() == HAVENSHIRE_FARMS || target->GetAreaId() == CRYPT_OF_REMEMBRANCE ||
               target->GetAreaId() == NEW_AVALON || target->GetAreaId() == NEW_AVALON_FORGE;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        switch (owner->GetAreaId())
        {
            case DEATHS_BREACH:
            case HAVENSHIRE:
            case HAVENSHIRE_STABLES:
            case HAVENSHIRE_LUMBER_MIL:
            case HAVENSHIRE_FARMS:
            case CRYPT_OF_REMEMBRANCE:
            case NEW_AVALON:
            case NEW_AVALON_FORGE:
                owner->RemoveAura(SPELL_BOUNDARY_WARNING);
                break;
        }

        if (owner->GetVehicleCreatureBase())
            return;

        owner->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* Vanquisher = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(Vanquisher, TEXT_FROSTBROOD, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING, true);
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

    bool Validate(SpellInfo const* /*SpellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOUNDARY_WARNING_3 });
    }

    bool CheckArea(Unit* target)
    {
        return target->GetAreaId() != THE_SHADOW_VAULT && target->GetAreaId() != WEEPING_QUARRY;
    }

    bool CheckZone(Unit* target)
    {
        return target->GetZoneId() != SHOLAZAR_BASIN && target->GetZoneId() != THE_STORM_PEAKS && target->GetZoneId() != ICECROWN_CIDADEL;
    }

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        if (Creature* soo = owner->GetVehicleCreatureBase())
        {
            Player* target = owner->ToPlayer();
            sCreatureTextMgr->SendChat(soo, TEXT_EMOTE, owner, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_NEUTRAL, false, target);
            owner->CastSpell(owner, SPELL_BOUNDARY_WARNING_3, true);
        }
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* owner = GetUnitOwner();
        uint32 areaId = owner->GetAreaId();
        uint32 zoneId = owner->GetZoneId();

        if (areaId == THE_SHADOW_VAULT || areaId == WEEPING_QUARRY || zoneId == SHOLAZAR_BASIN)
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
