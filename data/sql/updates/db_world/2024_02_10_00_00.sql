-- DB update 2024_01_28_00_00 -> 2024_02_10_00_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_select_target_dead';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45980, 'spell_gen_select_target_dead'),
(32307, 'spell_gen_select_target_dead'),
(32314, 'spell_gen_select_target_dead'),
(52090, 'spell_gen_select_target_dead'),
(46023, 'spell_gen_select_target_dead');

-- Quest Re-Cursive
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 45980) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);

-- Quest Scalps!
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 52090) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 52090) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 28600) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 52090) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 28465) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 52090, 0, 0, 31, 1, 3, 28600, 0, 0, 0, 0, '', 'Scalp a troll from Heb\'Drakkar. You should first loot the corpse as it will despawn after being scalped.'),
(17, 0, 52090, 0, 1, 31, 1, 3, 28465, 0, 0, 0, 0, '', 'Scalp a troll from Heb\'Drakkar. You should first loot the corpse as it will despawn after being scalped.');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 52090) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 1) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 52083) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 52090) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 1) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 52083) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 52090, 0, 0, 1, 1, 52083, 0, 0, 1, 0, 0, '', 'Ahunae\'s Knife'),
(17, 0, 52090, 0, 1, 1, 1, 52083, 0, 0, 1, 0, 0, '', 'Ahunae\'s Knife');

-- Quest Master and Servant
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 46023) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 46023) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 46023) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 46023) AND (`SourceId` = 0) AND (`ElseGroup` = 3) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 46023) AND (`SourceId` = 0) AND (`ElseGroup` = 4) AND (`ConditionTypeOrReference` = 36) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 0) AND (`ConditionValue2` = 0) AND (`ConditionValue3` = 0);
