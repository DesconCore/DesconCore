-- update 2024_04_26_00_01 -> 2024_04_26_00_02

UPDATE `creature_template` SET `ScriptName` = 'npc_bone_gryphon' WHERE (`entry` = 30335);
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_bone_gryphon' WHERE (`entry` = 29648);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 29648);
