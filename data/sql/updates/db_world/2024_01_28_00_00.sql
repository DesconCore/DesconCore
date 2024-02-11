-- DB update 2023_05_29_02 -> 2024_01_28_00_00
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 19354) AND (`source_type` = 0) AND (`id` IN (2, 3, 4));

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 35460) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 19354) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 35460, 0, 0, 31, 1, 3, 19354, 0, 0, 0, 0, '', 'Use on Arzeth the Merciless to temporarily remove his powers.');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q10369_fury_of_the_dreghood_elders';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(35460, 'spell_q10369_fury_of_the_dreghood_elders');
