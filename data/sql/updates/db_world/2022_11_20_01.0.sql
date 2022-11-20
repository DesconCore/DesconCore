-- DB update 2022_11_20_00.0 -> 2022_11_20_01.0
--
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 29917) AND (`SourceId` = 0) AND (`ElseGroup` = 0) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17113) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 29917) AND (`SourceId` = 0) AND (`ElseGroup` = 1) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17111) AND (`ConditionValue3` = 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceGroup` = 0) AND (`SourceEntry` = 29917) AND (`SourceId` = 0) AND (`ElseGroup` = 2) AND (`ConditionTypeOrReference` = 31) AND (`ConditionTarget` = 1) AND (`ConditionValue1` = 3) AND (`ConditionValue2` = 17112) AND (`ConditionValue3` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 29917, 0, 0, 31, 1, 3, 17113, 0, 0, 0, 0, '', 'Captured Crocolisk'),
(17, 0, 29917, 0, 1, 31, 1, 3, 17111, 0, 0, 0, 0, '', 'Captured Jaguar'),
(17, 0, 29917, 0, 2, 31, 1, 3, 17112, 0, 0, 0, 0, '', 'Captured Tarantula');
