-- DB update 2022_11_25_00.0 -> 2022_12_05_00.0
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 12298;

DELETE FROM `smart_scripts` WHERE (`entryorguid` = 12298) AND (`source_type` = 0)
