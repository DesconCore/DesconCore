-- DB update 2024_01_28_00_00 -> 2024_02_10_00_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_select_target_dead';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45980, 'spell_gen_select_target_dead'),
(32307, 'spell_gen_select_target_dead'),
(32314, 'spell_gen_select_target_dead');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 45980) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);

