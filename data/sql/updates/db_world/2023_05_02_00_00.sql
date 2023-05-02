-- DB update 2023_03_05_05 -> 2023_05_02_00_00
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 29414) AND (`source_type` = 0) AND (`id` IN (2, 4));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29414, 0, 2, 4, 28, 0, 100, 512, 0, 0, 0, 0, 0, 11, 45472, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Bone Gryphon - On Passenger Removed - Cast \'Parachute\''),
(29414, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 28, 51272, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Bone Gryphon - On Passenger Removed - Remove Aura \'Boundary Warning\'');

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 29403) AND (`source_type` = 0) AND (`id` IN (2, 3));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29403, 0, 2, 3, 28, 0, 100, 0, 0, 0, 0, 0, 0, 11, 45472, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Gryphon - On Passenger Removed - Cast \'Parachute\''),
(29403, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 28, 51272, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Gryphon - On Passenger Removed - Remove Aura \'Boundary Warning\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 30228;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 30228);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30228, 0, 0, 0, 28, 0, 100, 0, 0, 0, 0, 0, 0, 28, 51272, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Argent Skytalon - On Passenger Removed - Remove Aura \'Boundary Warning\'');

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 27996) AND (`source_type` = 0) AND (`id` IN (4, 2));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27996, 0, 4, 2, 28, 0, 100, 512, 0, 0, 0, 0, 0, 80, 2799600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'WYRMREST VANQUISHER - PASSENGER_REMOVED - Actionlist'),
(27996, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 28, 51272, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Wyrmrest Vanquisher - On Passenger Removed - Remove Aura \'Boundary Warning\'');

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 27629) AND (`source_type` = 0) AND (`id` IN (4));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27629, 0, 4, 0, 28, 0, 100, 0, 0, 0, 0, 0, 0, 28, 50065, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Wyrmrest Defender - On Passenger Removed - Remove Aura \'Warning\'');

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 27292) AND (`source_type` = 0) AND (`id` IN (6, 7));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27292, 0, 6, 7, 28, 0, 100, 512, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On Passenger Removed - Despawn Instant'),
(27292, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 28, 48694, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Flamebringer - On Passenger Removed - Remove Aura \'Warning\'');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28670;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 28670);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28670, 0, 0, 1, 28, 0, 100, 0, 0, 0, 0, 0, 0, 28, 51272, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Frostbrood Vanquisher - On Passenger Removed - Remove Aura \'Boundary Warning\''),
(28670, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 45472, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0, 'Frostbrood Vanquisher - On Passenger Removed - Cast \'Parachute\'');
