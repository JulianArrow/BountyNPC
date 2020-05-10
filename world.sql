Set @NpcName = "Bounty NPC",
	@NpcSubname = "",
	@NpcEntry = 55002,
	@NpcDisplayID = 31833,
	@NpcLevel = 255,
	@Scriptname = 'Bounty_NPC';

INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(@NpcEntry, 0, 0, 0, 0, 0, @NpcDisplayID, 0, 0, 0, @NpcName, @NpcSubname, '', 0, @NpcLevel, @NpcLevel, 0, 35, 1, 1, 1.14286, 1, 1, 0, 2000, 2000, 1, 1, 2, 0, 2048, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 50, 50, 1, 1, 1, 0, 0, 1, 0, 0, 0, @Scriptname, 12340);

CREATE TABLE IF NOT EXISTS `bounty_quests` (
  `ID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `bounty_quests` (`ID`) VALUES
	(11488),
	(12801),
	(13094);