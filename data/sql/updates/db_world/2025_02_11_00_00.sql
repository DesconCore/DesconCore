-- update 2025_02_06_00_02 -> 2025_02_11_00_00
UPDATE creature_template SET ScriptName = 'npc_flamebringer', AIName = '' WHERE entry = 27292;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 27292);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_summon_flamebringer';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48595, 'spell_summon_flamebringer');
