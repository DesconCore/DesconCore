-- update 2025_02_22_01_00 -> 2025_03_01_00_00
-- Dream Vision
UPDATE `creature_template` SET `unit_flags` = 131072, `ScriptName` = 'npc_controller' WHERE (`entry` = 7863);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dream_vision';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(11403, 'spell_dream_vision'); -- Dream Vision
