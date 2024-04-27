-- update 2024_04_26_00_04 -> 2024_04_26_00_00
DELETE FROM `spell_script_names` WHERE  `spell_id`=61122 AND `ScriptName`='spell_item_branns_communicator';

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=61122 AND `spell_effect`=55038 AND `type`=0;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(61122, 55038, 0, 'Contact Brann');
