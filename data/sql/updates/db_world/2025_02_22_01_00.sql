-- update 2025_02_22_00_00 -> 2025_02_22_01_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_12779_call_of_the_frostbrood';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53173,  'spell_12779_call_of_the_frostbrood');
