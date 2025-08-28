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

#ifndef AREA_LIMITATION_H
#define AREA_LIMITATION_H

#include "ScriptMgr.h"

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

enum AreaIDs
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

enum ZoneIds
{
    ICECROWN                                 = 210,
    SHOLAZAR_BASIN                           = 3711,
    THE_STORM_PEAKS                          = 67,
    ICECROWN_CIDADEL                         = 4812
};

static const uint32 RestrictedAreaFlamebringer = VOLDRUNE;
static const uint32 RestrictedAreaOnslaughtHarbor = ONSLAUGHT_HARBOR;
static const uint32 RestrictedZoneOnslaughtGryphon = ICECROWN;
static const std::unordered_set<uint32> RestrictedAreasWyrmrestDefenderMount = {
    THE_DRAGON_WASTES,
    PATH_OF_THE_TITANS,
    AZURE_DRAGONSHRINE,
    THE_MIRROR_OF_DAWN,
    WYRMREST_TEMPLE
};
static const std::unordered_set<uint32> RestrictedAreasWintergardeGryphonCommander = {
    WINTERGARDE_KEEP,
    WINTERGARDE_MINE,
    THE_CARRION_FIELDS
};
static const std::unordered_set<uint32> RestrictedAreasRideFreedProtoDrake = {
    DUN_NIFFELEM,
    VALLEY_OF_ANCIENT_WINTERS,
    BRUNNHILDAR_VILLAGE,
    THE_PIT_OF_THE_FANG
};
static const std::unordered_set<uint32> RestrictedAreasArgentSkytalon = {
    THE_ARGENT_VANGUARD,
    VALLEY_OF_ECHOES,
    THE_BREACH,
    SCOURGEHOLME
};
static const std::unordered_set<uint32> RestrictedAreasWyrmrestCommander = {
    WYRMREST_TEMPLE,
    THE_DRAGON_WASTES,
    GALAKRONDS_REST,
    THE_WICKED_COIL,
    PATH_OF_THE_TITANS
};
static const std::unordered_set<uint32> RestrictedAreaKorkronWingCommander = {
    ICEMIST_VILLAGE
};
static const std::unordered_set<uint32> RestrictedAreaFrostbroodVanquisher = {
    DEATHS_BREACH,
    HAVENSHIRE,
    HAVENSHIRE_STABLES,
    HAVENSHIRE_LUMBER_MIL,
    HAVENSHIRE_FARMS,
    CRYPT_OF_REMEMBRANCE,
    NEW_AVALON,
    NEW_AVALON_FORGE
};
static const std::unordered_set<uint32> RestrictedAreasRideVehicleHardcoded = {
    THE_SHADOW_VAULT,
    WEEPING_QUARRY
};

static const std::unordered_set<uint32> RestrictedZonesRideVehicleHardcoded = {
    SHOLAZAR_BASIN,
    THE_STORM_PEAKS,
    ICECROWN_CIDADEL
};

#endif
