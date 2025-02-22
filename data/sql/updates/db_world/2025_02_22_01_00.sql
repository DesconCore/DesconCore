-- update 2025_02_22_00_00 -> 2025_02_22_01_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_12779_call_of_the_frostbrood';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_devour_humanoid';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53173,  'spell_12779_call_of_the_frostbrood'),
(53110,  'spell_devour_humanoid');

-- not necessary
DELETE FROM `npc_spellclick_spells` WHERE  `npc_entry`=28670 AND `spell_id`=53173;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_frostbrood_vanquisher' WHERE (`entry` = 28670);
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 28670);

UPDATE `creature_template` SET `ScriptName` = 'npc_crusader' WHERE `entry` IN (29102,29103);

SET @NPC_HEARTHGLEN_CRUSADER := 29102;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_HEARTHGLEN_CRUSADER;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_HEARTHGLEN_CRUSADER, 0, 0, 'Let the purging begin!', 12, 0, 100, 0, 0, 0, 29720, 0, 'SAY_GET_CRUSADER'),
(@NPC_HEARTHGLEN_CRUSADER, 0, 1, 'Scourge filth! DIE!', 12, 0, 100, 0, 0, 0, 28597, 0, 'SAY_GET_CRUSADER'),
(@NPC_HEARTHGLEN_CRUSADER, 0, 2, 'You\'re not welcome in these lands, monster!', 12, 0, 100, 0, 0, 0, 29719, 0, 'SAY_GET_CRUSADER'),
(@NPC_HEARTHGLEN_CRUSADER, 0, 3, 'The Crusade will be victorious!', 12, 0, 100, 0, 0, 0, 29717, 0, 'SAY_GET_CRUSADER'),
(@NPC_HEARTHGLEN_CRUSADER, 0, 4, 'I will present your head to Abbendis myself!', 12, 0, 100, 0, 0, 0, 28599, 0, 'SAY_GET_CRUSADER');

SET @NPC_TIRISFAL_CRUSADER := 29103;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC_TIRISFAL_CRUSADER;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_TIRISFAL_CRUSADER, 0, 0, 'You\'re not welcome in these lands, monster!', 12, 0, 100, 0, 0, 0, 29719, 0, 'SAY_GET_CRUSADER'),
(@NPC_TIRISFAL_CRUSADER, 0, 1, 'I will present your head to Abbendis myself!', 12, 0, 100, 0, 0, 0, 28599, 0, 'SAY_GET_CRUSADER'),
(@NPC_TIRISFAL_CRUSADER, 0, 2, 'Scourge filth! DIE!', 12, 0, 100, 0, 0, 0, 28597, 0, 'SAY_GET_CRUSADER'),
(@NPC_TIRISFAL_CRUSADER, 0, 3, 'The Crusade will be victorious!', 12, 0, 100, 0, 0, 0, 29717, 0, 'SAY_GET_CRUSADER'),
(@NPC_TIRISFAL_CRUSADER, 0, 4, 'Let the purging begin!', 12, 0, 100, 0, 0, 0, 29720, 0, 'SAY_GET_CRUSADER');
