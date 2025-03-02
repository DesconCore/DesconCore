-- update 2025_02_22_01_00 -> 2025_03_01_00_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_eye_of_kilrogg';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(126, 'spell_warl_eye_of_kilrogg'); -- Eye of Kilrogg
