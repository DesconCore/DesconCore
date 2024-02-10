-- DB update 2023_01_01_01_00 -> 2023_01_19_00_00
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_plant_warmaul_ogre_banner';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_plant_kil_sorrow_banner';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(32307, 'spell_plant_warmaul_ogre_banner'),
(32314, 'spell_plant_kil_sorrow_banner');

DELETE FROM `event_scripts` WHERE  `id`=11669 AND `delay`=1 AND `command`=8 AND `datalong`=18388 AND `datalong2`=1 AND `dataint`=0 AND `x`=0 AND `y`=0 AND `z`=0 AND `o`=0 LIMIT 1;

-- quest Ruthless Cunning
-- change to Spell

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 3) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17148) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 3) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 18658) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 3) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17147) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 3) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 3) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17146) AND (`ConditionValue3` = 0);

-- Places Warmaul Ogre Banner on top of a fallen Kil'sorrow agent.
-- Does not take part in quest
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 3) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 4) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 18391) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 4) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17148) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 4) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182353) AND (`ConditionValue2` = 10) AND (`ConditionValue3` = 0);

-- delete condition dead
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17148) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17148) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 3) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17148) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17148) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 18658) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17147) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 3) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17146) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);

-- distance 0 in yard
UPDATE `conditions` SET `ConditionTarget` = 1, `ConditionValue2` = 0, `ErrorType` = 22 WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182353) AND (`ConditionValue2` = 10) AND (`ConditionValue3` = 0);
UPDATE `conditions` SET `ConditionTarget` = 1, `ConditionValue2` = 0, `ErrorType` = 22 WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182353) AND (`ConditionValue2` = 10) AND (`ConditionValue3` = 0);
UPDATE `conditions` SET `ConditionTarget` = 1, `ConditionValue2` = 0, `ErrorType` = 22 WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182353) AND (`ConditionValue2` = 10) AND (`ConditionValue3` = 0);
UPDATE `conditions` SET `ConditionTarget` = 1, `ConditionValue2` = 0, `ErrorType` = 22 WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32307) AND (`SourceId` = 0) AND (`ElseGroup` = 3) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182353) AND (`ConditionValue2` = 10) AND (`ConditionValue3` = 0);

-- quest Returning the Favor
-- change to spell
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 3) AND (`SourceEntry` = 32314) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17138) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceGroup` = 3) AND (`SourceEntry` = 32314) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 18064) AND (`ConditionValue3` = 0);

-- delete condition dead
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32314) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 17138) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32314) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 29) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 18064) AND (`ConditionValue2` = 5) AND (`ConditionValue3` = 1);

-- distance 0 in yard
UPDATE `conditions` SET `ConditionTarget` = 1, `ConditionValue2` = 0, `ErrorType` = 22 WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32314) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182354) AND (`ConditionValue2` = 10) AND (`ConditionValue3` = 0);
UPDATE `conditions` SET `ConditionTarget` = 1, `ConditionValue2` = 0, `ErrorType` = 22 WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 32314) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 30) AND (`ConditionTarget` = 0) AND (`ConditionValue1` = 182354) AND (`ConditionValue2` = 10) AND (`ConditionValue3` = 0);
