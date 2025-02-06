-- update 2024_04_27_00_01 -> 2025_02_06_00_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q11146_capture_raptor';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42325, 'spell_q11146_capture_raptor');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 4351;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 4351);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param6`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4351, 0, 0, 2, 25, 0, 100, 0, 0, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bloodfen Raptor - On Reset - Set Reactstate Aggressive'),
(4351, 0, 1, 0, 2, 0, 100, 1, 0, 20, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bloodfen Raptor - Between 0-20% Health - Say Line 0 (Phase 1) (No Repeat)'),
(4351, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 0, 19, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bloodfen Raptor - On Reset - Remove Flags Not Attackable');

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 4352);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param6`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4352, 0, 0, 2, 25, 0, 100, 0, 0, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bloodfen Screecher - On Reset - Set Reactstate Aggressive'),
(4352, 0, 1, 0, 2, 0, 100, 1, 0, 20, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bloodfen Screecher - Between 0-20% Health - Say Line 0 (No Repeat)'),
(4352, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 0, 19, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bloodfen Screecher - On Reset - Remove Flags Not Attackable');
