// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryKitEnums.generated.h"

/**
 * Inventory Kit Library of Enums
 */

UENUM(BlueprintType)
enum class EBaseGearType : uint8
{
	Select UMETA(DisplayName="Select"),
	Weapon UMETA(DisplayName="Weapon"),
	Armor UMETA(DisplayName="Armor")
};

UENUM(BlueprintType)
enum class EEquipWeaponType : uint8
{
	Select UMETA(DisplayName="Select"),
	PrimaryWeapon UMETA(DisplayName="Primary Weapon"),
	SecondaryWeapon UMETA(DisplayName="Secondary Weapon")
};

UENUM(BlueprintType)
enum class EGearCategory : uint8
{
	Select UMETA(DisplayName="Select"),
	Swords UMETA(DisplayName="Swords"),
	Spears UMETA(DisplayName="Spears"),
	Daggers UMETA(DisplayName="Daggers"),
	Heavy_Blunts UMETA(DisplayName="Heavy Blunts"),
	Heavy_Bladed UMETA(DisplayName="Heavy Bladed"),
	Staffs UMETA(DisplayName="Staffs"),
	Common UMETA(DisplayName="Common"),
	Rare UMETA(DisplayName="Rare"),
	Epic UMETA(DisplayName="Epic"),
	Legendary UMETA(DisplayName="Legendary")
};

UENUM(BlueprintType)
enum class EGearMeshType : uint8
{
	SingleOnRight UMETA(DisplayName="Single On Right"),
	SingleOnLeft UMETA(DisplayName="Single On Left"),
	DualMesh UMETA(DisplayName="Dual Mesh")
};

UENUM(BlueprintType)
enum class EGearType : uint8
{
	Select UMETA(DisplayName="Select"),
	Helmet UMETA(DisplayName="Helmet"),
	Torso UMETA(DisplayName="Torso"),
	Gauntlet UMETA(DisplayName="Gauntlet"),
	Pteruges UMETA(DisplayName="Pteruges"),
	Legs UMETA(DisplayName="Legs"),
	Weapon UMETA(DisplayName="Weapon"),
	Quiver UMETA(DisplayName="Quiver"),
	Bow UMETA(DisplayName="Bow"),
	Ride UMETA(DisplayName="Ride")
};

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	Select UMETA(DisplayName="Select"),
	Common UMETA(DisplayName="Common"),
	Rare UMETA(DisplayName="Rare"),
	Epic UMETA(DisplayName="Epic"),
	Legendary UMETA(DisplayName="Legendary")
};

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Select UMETA(DisplayName="Select"),
	Gear UMETA(DisplayName="Gear"),
	QuestItem UMETA(DisplayName="Quest Item"),
	Document UMETA(DisplayName="Document"),
	TradeGood UMETA(DisplayName="Trade Good")
};

UENUM(BlueprintType)
enum class EMontageAction : uint8
{
	Select UMETA(DisplayName="Select"),
	EquipWeapon UMETA(DisplayName="Equip Weapon"),
	UnequipWeapon UMETA(DisplayName="Unequip Weapon")
};

UENUM(BlueprintType)
enum class EPerkTypes : uint8
{
	Select UMETA(DisplayName="Select"),
	WarriorDamage UMETA(DisplayName="Warrior Damage"),
	HunterDamage UMETA(DisplayName="Hunter Damage"),
	AssassinDamage UMETA(DisplayName="Assassin Damage"),
	CriticalDamage UMETA(DisplayName="Critical Damage"),
	PoisonDamage UMETA(DisplayName="Poison Damage"),
	FireDamage UMETA(DisplayName="Fire Damage"),
	Health UMETA(DisplayName="Health"),
	TotalArmor UMETA(DisplayName="Total Armor")
};

UENUM(BlueprintType)
enum class EWeaponSelectedAs : uint8
{
	NotAWeapon UMETA(DisplayName="Not A Weapon"),
	WeaponA UMETA(DisplayName="Weapon A"),
	WeaponB UMETA(DisplayName="Weapon B")
};
