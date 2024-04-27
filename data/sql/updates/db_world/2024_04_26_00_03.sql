-- update 2024_04_26_00_02 -> 2024_04_26_00_03
-- quest Screecher Spirits
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 12699) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 5307) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 12699) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 5308) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 12699, 0, 0, 31, 1, 3, 5307, 0, 0, 0, 0, '', ' Summon a screecher spirit from the corpse of a vale screecher.'),
(17, 0, 12699, 0, 1, 31, 1, 3, 5308, 0, 0, 0, 0, '', ' Summon a screecher spirit from the corpse of a vale screecher.');

UPDATE `spell_script_names` SET `ScriptName`='spell_gen_select_target_dead' WHERE  `spell_id`=12699 AND `ScriptName`='spell_gen_yehkinya_bramble';

-- quest Final Preparations
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 27360) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 16042) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 27360, 0, 0, 31, 1, 3, 16042, 0, 0, 0, 0, '', 'Target Lord Valthalak\'s corpse to instill his spirit from the amulet.');

UPDATE `spell_script_names` SET `ScriptName`='spell_gen_select_target_dead' WHERE  `spell_id`=27360 AND `ScriptName`='spell_gen_valthalak_amulet';

-- quest Standards and Practices
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32205) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182263) AND (`ConditionValue2` = 6) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32205) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182264) AND (`ConditionValue2` = 6) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32205) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182262) AND (`ConditionValue2` = 6) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 32205, 0, 0, 30, 0, 182263, 6, 0, 0, 0, 0, '', 'Distance Required.'),
(17, 0, 32205, 0, 1, 30, 0, 182264, 6, 0, 0, 0, 0, '', 'Distance Required.'),
(17, 0, 32205, 0, 2, 30, 0, 182262, 6, 0, 0, 0, 0, '', 'Distance Required.');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_dest_caster_summon';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(32205, 'spell_gen_dest_caster_summon');

