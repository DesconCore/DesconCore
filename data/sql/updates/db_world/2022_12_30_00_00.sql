-- DB update 2022_12_14_00_00 -> 2022_12_30_00_00
-- https://wowpedia.fandom.com/wiki/Arelion%27s_Mistres
-- Use the scroll on her, giving her the Carinda's Retribution buff.
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 30077) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17226) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 30077, 0, 0, 31, 1, 3, 17226, 0, 0, 0, 0, '', 'Unleashes spell prepared by Magistrix Carinda for Viera Sunwhisper');

-- WP start
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 1722600) AND (`source_type` = 9) AND (`id` IN (5));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1722600, 9, 5, 0, 0, 0, 100, 0, 36000, 36000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - Actionlist - Say Line 1');

-- remove white space
UPDATE `creature_text` SET `Text`='Ok, let\'s go. I know just the perfect spot!' WHERE  `CreatureID`=17226 AND `GroupID`=0 AND `ID`=0;
UPDATE `broadcast_text` SET `FemaleText`='Ok, let\'s go. I know just the perfect spot!' WHERE  `ID`=13589;
UPDATE `creature_text` SET `Text`='What... is happening... to me? Get this cat away from me!' WHERE  `CreatureID`=17226 AND `GroupID`=2 AND `ID`=0;
UPDATE `broadcast_text` SET `FemaleText`='What... is happening... to me? Get this cat away from me!' WHERE  `ID`=13591;

-- change (Twinkle)
UPDATE `creature_text` SET `CreatureID`=17230, `GroupID`=1, `Text`='Viera Sunwhisper scurries away, attempting to flee from Twinkle.', `comment`='Twinkle' WHERE  `CreatureID`=17226 AND `GroupID`=3 AND `ID`=0;
UPDATE `broadcast_text` SET `MaleText`='Viera Sunwhisper scurries away, attempting to flee from Twinkle.', `FemaleText`='' WHERE  `ID`=13610;

-- there is no use
-- used by the phase to fix a bug
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 1722601);

-- WP end
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17226);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17226, 0, 0, 0, 20, 0, 100, 512, 9483, 0, 0, 0, 0, 80, 1722600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Quest \'Life\'s Finer Pleasures\' Finished - Run Script'),
(17226, 0, 1, 2, 40, 0, 100, 512, 10, 17226, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 17230, 15, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Waypoint 10 Reached - Set Orientation Closest Creature \'Twinkle\''),
(17226, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 54, 1000000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Waypoint 10 Reached - Pause Waypoint'),
(17226, 0, 3, 0, 8, 0, 100, 0, 30077, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Spellhit \'Carinda`s Retribution\' - Set Event Phase 2'),
(17226, 0, 4, 0, 40, 0, 100, 512, 4, 172260, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Waypoint 4 Reached - Despawn Instant'),
(17226, 0, 5, 6, 60, 2, 100, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Update - Say Line 2 (Phase 2)'),
(17226, 0, 6, 0, 61, 2, 100, 0, 0, 0, 0, 0, 0, 33, 17226, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Update - Quest Credit \'null\' (Phase 2)'),
(17226, 0, 7, 0, 1, 2, 100, 0, 5500, 5500, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 9, 17230, 0, 25, 0, 0, 0, 0, 0, 'Viera Sunwhisper - Out of Combat - Say Line 0 (Phase 2)'),
(17226, 0, 8, 0, 60, 2, 100, 0, 7500, 7500, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 9, 17230, 0, 25, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Update - Say Line 1 (Phase 2)'),
(17226, 0, 9, 10, 60, 2, 100, 0, 3000, 3000, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, 61963, 17230, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Update - Set Data 1 2 (Phase 2)'),
(17226, 0, 10, 0, 61, 2, 100, 0, 0, 0, 0, 0, 0, 53, 1, 172260, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Viera Sunwhisper - On Update - Start Waypoint (Phase 2)');
