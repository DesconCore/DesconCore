-- DB update 2022_11_04_02_0 -> 2022_11_04_02_1

-- Guardian of Time's creature_text
DELETE FROM `creature_text` WHERE `creatureID` = 32281;
INSERT INTO `creature_text` (`creatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `broadcastTextId`, `TextRange`, `comment`) VALUES
(32281, 0, 0, 'You have my thanks for saving my existence in this timeline. Now I must report back to my superiors. They must know immediately of what I just experienced.', 12, 0, 100, 0, 0, 0, 32645, 0, 'Guardian of Time - SAY_SUCCESS');

DELETE FROM `creature_template_addon` WHERE  `entry`=32281;
