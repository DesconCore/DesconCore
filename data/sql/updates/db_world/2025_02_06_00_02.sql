-- update 2025_02_06_00_01 -> 2025_02_06_00_02
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen__pvp_master';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50467, 'spell_gen__pvp_master'), -- Blackriver PvP Master
(50855, 'spell_gen__pvp_master'), -- Blue Sky PvP Master
(50857, 'spell_gen__pvp_master'); -- Venture Bay PvP Master
