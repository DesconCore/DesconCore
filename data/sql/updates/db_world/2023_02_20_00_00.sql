-- DB update 2023_02_07_00 -> 2023_02_20_00_00
UPDATE `creature_template` SET `ScriptName`='npc_marmot' WHERE `entry`=22189;

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_coax_marmot';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38544, 'spell_coax_marmot');
