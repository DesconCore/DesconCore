-- DB update 2022_12_30_00_00 -> 2023_01_01_00_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q10839_rod_of_purification';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38736, 'spell_q10839_rod_of_purification');
