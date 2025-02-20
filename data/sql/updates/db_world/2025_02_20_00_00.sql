-- update 2025_02_11_00_00 -> 2025_02_20_00_00
UPDATE `creature_template` SET `unit_flags` = 131072 WHERE (`entry` = 22189);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_charm_rexxars_rodent';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_stealth_marmot';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38586, 'spell_charm_rexxars_rodent'),
(42347, 'spell_stealth_marmot');
