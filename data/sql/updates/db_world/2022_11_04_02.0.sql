-- DB update 2022_11_04_01 -> 2022_11_04_02_0
--
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hatch_rookery_egg';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(15746, 'spell_hatch_rookery_egg');

-- is no longer necessary
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 15958) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 175124) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 0);
