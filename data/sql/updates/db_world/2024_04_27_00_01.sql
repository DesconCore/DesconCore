-- update 2024_04_26_00_00 -> 2024_04_26_00_01
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_dest_caster_summon';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(32205, 'spell_gen_dest_caster_summon'), -- Place Mag'har Battle Standard
(55038, 'spell_gen_dest_caster_summon'); -- Contact Brann
