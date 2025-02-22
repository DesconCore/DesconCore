-- update 2025_02_20_00_00 -> 2025_02_22_00_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_summon_raven_god';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(40098,  'spell_summon_raven_god');
