-- update 2024_04_26_00_00 -> 2024_04_26_00_01
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_call_arthorns_sparrowhawk';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(40889, 'spell_call_arthorns_sparrowhawk');

UPDATE `creature_template` SET `ScriptName` = 'npc_Arthorns_sparrowhawk' WHERE (`entry` = 23338);
