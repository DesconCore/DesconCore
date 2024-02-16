-- DB update 2024_02_10_00_00 -> 2024_02_16_00_00
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 18688;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 18688);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18688, 0, 0, 1, 8, 0, 100, 513, 34063, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - On Spellhit \'Soul Mirror\' - Say Line 0 (No Repeat)'),
(18688, 0, 1, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - On Spellhit \'Soul Mirror\' - Set Event Phase 1'),
(18688, 0, 2, 3, 1, 1, 100, 512, 2000, 2000, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - Out of Combat - Kill Self (Phase 1)'),
(18688, 0, 3, 0, 61, 1, 100, 0, 0, 0, 0, 0, 0, 12, 19480, 7, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ancient Orc Ancestor - On Spellhit \'Soul Mirror\' - Summon Creature \'Darkened Spirit\' (No Repeat)');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19480;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 19480);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19480, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 11000, 15000, 0, 11, 31293, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkened Spirit - In Combat - Cast \'Consuming Shadows\''),
(19480, 0, 1, 0, 54, 0, 100, 512, 0, 0, 0, 0, 0, 11, 17321, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkened Spirit - On Just Summoned - Cast \'Spirit Spawn-in\'');
