-- DB update 2022_11_06_00 -> 2022_11_06_01_0
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_ride_vehicle_hardcoded';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_boundary_warning';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_frostbrood_vanquisher';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_korkron_wing_commander';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_wyrmrest_commander';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_command_argent_skytalon';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_ride_freed_proto_drake';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_onslaught_gryphon';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_bone_gryphon';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_ride_flamebringer';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_wyrmrest_defender_mount';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_wintergarde_gryphon_commander';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_purge_vehicle_control';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43813, 'spell_gen_purge_vehicle_control'),
(48205, 'spell_gen_purge_vehicle_control'),
(48367, 'spell_gen_purge_vehicle_control'),
(48706, 'spell_gen_purge_vehicle_control'),
(49087, 'spell_gen_purge_vehicle_control'),
(50068, 'spell_gen_purge_vehicle_control'),
(48365, 'spell_wintergarde_gryphon_commander'),
(49256, 'spell_wyrmrest_defender_mount'),
(48600, 'spell_ride_flamebringer'),
(21745, 'spell_bone_gryphon'),
(49641, 'spell_onslaught_gryphon'),
(55029, 'spell_ride_freed_proto_drake'),
(56678, 'spell_command_argent_skytalon'),
(50343, 'spell_wyrmrest_commander'),
(47424, 'spell_korkron_wing_commander'),
(52196, 'spell_frostbrood_vanquisher'),
(51272, 'spell_gen_boundary_warning'),
(51259, 'spell_gen_boundary_warning'),
(56966, 'spell_gen_boundary_warning'),
(46598, 'spell_ride_vehicle_hardcoded');

SET @NPC_FLAMRBRINGER := 27292;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_FLAMRBRINGER;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_FLAMRBRINGER, 0, 0, 'Flamebringer attempts to throw you from his back. Return to Voidrune!', 42, 0, 100, 0, 0, 0, 26546, 0, 'Area Warning');

SET @NPC_WYRMREST_DEFENDER := 27629;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_WYRMREST_DEFENDER;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_WYRMREST_DEFENDER, 0, 0, 'Turn around and get back in the fight flight or i\'ll have to drop you off!', 42, 0, 100, 0, 0, 0, 27342, 0, 'Area Warning');

SET @NPC_WINTERGARDE_GRYPHON := 27258;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_WINTERGARDE_GRYPHON;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_WINTERGARDE_GRYPHON, 0, 0, 'Return to Wintergarde or the Carrion Fields or your gryphon will drop you!', 42, 0, 100, 0, 0, 0, 26372, 0, 'Area Warning');

SET @NPC_BONE_GRYPHON := 29414;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_BONE_GRYPHON;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_BONE_GRYPHON, 0, 0, 'Return to Onslaught Harbor or lose your Bone Gryphon!', 42, 0, 100, 0, 0, 0, 30115, 0, 'Area Warning');

SET @NPC_ONSLAUGHT_GRYPHON := 29403;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_ONSLAUGHT_GRYPHON;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_ONSLAUGHT_GRYPHON, 0, 0, 'Return to Icecrown or lose the Onslaught Gryphon!', 42, 0, 100, 0, 0, 0, 30114, 0, 'Area Warning');

SET @FREED_PROTO_DRAKE := 29709;
UPDATE `creature_text` SET `GroupID`='1', `ID`='0' WHERE  `CreatureID`=@FREED_PROTO_DRAKE AND `GroupID`=0 AND `ID`=1;

SET @ARGENT_SKYTALON := 30228;
DELETE FROM `creature_text` WHERE `CreatureID`=@ARGENT_SKYTALON;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@ARGENT_SKYTALON, 0, 0, 'You may only fly in the Argent Vanguard, Valley of Echoes and Scourgeholme.', 42, 0, 100, 0, 0, 0, 31131, 0, 'Area Warning');

SET @NPC_WYRMREST_VANQUISHER := 27996;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_WYRMREST_VANQUISHER AND `GroupID`=3 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_WYRMREST_VANQUISHER, 3, 0, 'Return to the field of battle or your dragon will drop you!', 42, 0, 100, 0, 0, 0, 27393, 0, 'Area Warning');

SET @NPC_KORKRON_WAR_RIDER := 26813;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_KORKRON_WAR_RIDER;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_KORKRON_WAR_RIDER, 0, 0, 'You may only fly in Icemist Village.', 42, 0, 100, 0, 0, 0, 27390, 0, 'Area Warning');

SET @NPC_FROSTBROOD_VANQUISHER := 28670;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_FROSTBROOD_VANQUISHER;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_FROSTBROOD_VANQUISHER, 0, 0, 'Avoid incoming Scarlet Crusade arrows and javelins by moving out of their line of fire!', 42, 0, 100, 0, 0, 0, 29888, 0, ''),
(@NPC_FROSTBROOD_VANQUISHER, 1, 0, 'Return to the field of battle or you will be dropped!', 42, 0, 100, 0, 0, 0, 29876, 0, 'Area Warning');

-- https://www.wowhead.com/wotlk/quest=12815/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 16 AND `SourceGroup` = 0 AND `SourceEntry` = 29414 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 23 AND `ConditionTarget` = 0 AND `ConditionValue1` = 4417 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;

-- https://www.wowhead.com/wotlk/quest=12255/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 16 AND `SourceGroup` = 0 AND `SourceEntry` = 27292 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 23 AND `ConditionTarget` = 0 AND `ConditionValue1` = 4207 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;

-- https://www.wowhead.com/quest=12372/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 16 AND `SourceGroup` = 0 AND `SourceEntry` = 27629 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 4 AND `ConditionTarget` = 0 AND `ConditionValue1` = 65 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;

-- https://www.wowhead.com/wotlk/quest=12237/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 16 AND `SourceGroup` = 0 AND `SourceEntry` = 27258 AND `SourceId` = 0 AND `ElseGroup` = 0 AND `ConditionTypeOrReference` = 23 AND `ConditionTarget` = 0 AND `ConditionValue1`= 4188 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 16 AND `SourceGroup` = 0 AND `SourceEntry` = 27258 AND `SourceId` = 0 AND `ElseGroup` = 1 AND `ConditionTypeOrReference` = 23 AND `ConditionTarget` = 0 AND `ConditionValue1`= 4177 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 16 AND `SourceGroup` = 0 AND `SourceEntry` = 27258 AND `SourceId` = 0 AND `ElseGroup` = 2 AND `ConditionTypeOrReference` = 23 AND `ConditionTarget` = 0 AND `ConditionValue1`= 4178 AND `ConditionValue2` = 0 AND `ConditionValue3` = 0;

-- https://www.wowhead.com/wotlk/quest=12498/
DELETE FROM `spell_area` WHERE `spell` = 50426;
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 16) AND (`SourceGroup` = 0) AND (`SourceEntry` = 27996) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 23) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 4161) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 16) AND (`SourceGroup` = 0) AND (`SourceEntry` = 27996) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 23) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 4254) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 16) AND (`SourceGroup` = 0) AND (`SourceEntry` = 27996) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 23) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 4173) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 16) AND (`SourceGroup` = 0) AND (`SourceEntry` = 27996) AND (`SourceId` = 0) AND (`ElseGroup` = 3) AND (`ConditionTypeOrReference` = 23) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 4174) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 16) AND (`SourceGroup` = 0) AND (`SourceEntry` = 27996) AND (`SourceId` = 0) AND (`ElseGroup` = 4) AND (`ConditionTypeOrReference` = 23) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 4184) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);

-- https://www.wowhead.com/wotlk/quest=12072/
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 16) AND (`SourceGroup` = 0) AND (`SourceEntry` = 26813) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 23) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 4163) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
