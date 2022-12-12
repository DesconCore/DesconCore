-- DB update 2022_12_10_00 -> 2022_12_11_00_00
--
UPDATE `broadcast_text` SET `MaleText`='Reporting for duty, sir!', `FemaleText`='Reporting for duty, sir!' WHERE  `ID`=10001;

SET @REPROGRAMMED_SCAVENGE_BOT_004_A8 := 25821;
SET @REPROGRAMMED_SENTRY_BOT_57K := 25823;
SET @REPROGRAMMED_DEFENDO_TANK_66D := 25820;
SET @REPROGRAMMED_SCAVENGE_BOT_005_B6 := 25822;
SET @REPROGRAMMED_55D_COLLECT_A_TRON := 25818;

DELETE FROM `creature_text` WHERE `CreatureID`=@REPROGRAMMED_SCAVENGE_BOT_004_A8;
DELETE FROM `creature_text` WHERE `CreatureID`=@REPROGRAMMED_SENTRY_BOT_57K;
DELETE FROM `creature_text` WHERE `CreatureID`=@REPROGRAMMED_DEFENDO_TANK_66D;
DELETE FROM `creature_text` WHERE `CreatureID`=@REPROGRAMMED_SCAVENGE_BOT_005_B6;
DELETE FROM `creature_text` WHERE `CreatureID`=@REPROGRAMMED_55D_COLLECT_A_TRON;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@REPROGRAMMED_SCAVENGE_BOT_004_A8, 0, 0, 'Reporting for duty, sir!', 12, 0, 100, 0, 0, 0, 10001, 0, 'text'),
(@REPROGRAMMED_SENTRY_BOT_57K, 0, 0, 'Reporting for duty, sir!', 12, 0, 100, 0, 0, 0, 10001, 0, 'text'),
(@REPROGRAMMED_DEFENDO_TANK_66D, 0, 0, 'Reporting for duty, sir!', 12, 0, 100, 0, 0, 0, 10001, 0, 'text'),
(@REPROGRAMMED_SCAVENGE_BOT_005_B6, 0, 0, 'Reporting for duty, sir!', 12, 0, 100, 0, 0, 0, 10001, 0, 'text'),
(@REPROGRAMMED_55D_COLLECT_A_TRON, 0, 0, 'Reporting for duty, sir!', 12, 0, 100, 0, 0, 0, 10001, 0, 'text');

UPDATE `creature_template` SET `ScriptName`='npcs_004a8_57k_66d_005b6_55d' WHERE `entry`=25821;
UPDATE `creature_template` SET `ScriptName`='npcs_004a8_57k_66d_005b6_55d' WHERE `entry`=25823;
UPDATE `creature_template` SET `ScriptName`='npcs_004a8_57k_66d_005b6_55d' WHERE `entry`=25820;
UPDATE `creature_template` SET `ScriptName`='npcs_004a8_57k_66d_005b6_55d' WHERE `entry`=25822;
UPDATE `creature_template` SET `ScriptName`='npcs_004a8_57k_66d_005b6_55d' WHERE `entry`=25818;
