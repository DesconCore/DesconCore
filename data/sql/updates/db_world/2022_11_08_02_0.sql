-- DB update 2022_11_08_01 -> 2022_11_08_02_0
-- time provided by the DBC does not work. As of now, I implemented via spell_proc_event
DELETE FROM `spell_proc_event` WHERE `entry`=43730;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(43730, 0, 0, 0, 0, 0, 0, 0, 0, 100, 8000);
