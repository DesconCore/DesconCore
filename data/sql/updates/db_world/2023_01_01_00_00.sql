-- DB update 2022_12_30_00_00 -> 2023_01_01_00_00

-- cannot be used after completion
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q10839_rod_of_purification';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38736, 'spell_q10839_rod_of_purification');

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 185191) AND (`source_type` = 1) AND (`id` IN (0, 1));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(185191, 1, 0, 1, 8, 0, 100, 0, 38729, 0, 0, 0, 0, 99, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkstone of Terokk - On Spellhit \'Rod of Purification\' - Set Lootstate Deactivated'),
(185191, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 10, 78342, 22288, 0, 0, 0, 0, 0, 0, 'Darkstone of Terokk - On Spellhit \'Rod of Purification\' - Despawn Instant'); -- npc Terokkar Quest Target removed after completion of quest, also cannot be used while completed.
