// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CombInv_EnumLibrary.generated.h"

UENUM(BlueprintType)
enum class EItemActions : uint8
{
	Use UMETA(DisplayName = "Use"),
	Equip UMETA(DisplayName = "Equip"),
	Drop UMETA(DisplayName = "Drop"),
	Delete UMETA(DisplayName = "Delete")
};

UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	Weapon UMETA(DisplayName = "Weapon"),
	Equipment UMETA(DisplayName = "Equipment"),
	Consumable UMETA(DisplayName = "Consumable"),
	Tool UMETA(DisplayName = "Tool"),
	Quest UMETA(DisplayName = "Quest"),
	Other UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class EItemProperty : uint8
{
	Weight UMETA(DisplayName = "Weight"),
	Price UMETA(DisplayName = "Price")
};

UENUM(BlueprintType)
enum class EActiveState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Attack UMETA(DisplayName = "Attack"),
	Stunt UMETA(DisplayName = "Stunt"),
	Interaction UMETA(DisaplyName = "Interaction")
};

UENUM(BlueprintType)
enum class EAttackDirection : uint8
{
	None UMETA(DisplayName = "None"),
	Top UMETA(DisplayName = "Top"),
	TopRight UMETA(DisplayName = "TopRight"),
	Right UMETA(DisplayName = "Right"),
	LowRight UMETA(DisplayName = "LowRight"),
	Low UMETA(DisplayName = "Low"),
	LowLeft UMETA(DisplayName = "LowLeft"),
	Left UMETA(DisplayName = "Left"),
	TopLeft UMETA(DisplayName = "TopLeft"),
	Middle UMETA(DisplayName = "Middle")
};

UENUM(BlueprintType)
enum class EActionInput : uint8
{
	Null UMETA(DisplayName = "Null"),
	LightAttack UMETA(DisplayName = "Light Attack"),
	HeavyAttack UMETA(DisplayName = "Heavy Attack"),
	Interaction UMETA(DisplayName = "Interaction")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Fist UMETA(DisplayName = "Fist"),
	Fencer UMETA(DisplayName = "Fencer"),
	TwoHandedSword UMETA(DisplayName = "Two Handed Sword"),
	SwordAndShield UMETA(DisplayName = "Sword and Shield"),
	Spear UMETA(DisplayName = "Spear"),
	Bow UMETA(DisplayName = "Bow")
};

UENUM(BlueprintType)
enum class EEquipmentType : uint8
{
    None UMETA(DisplayName = "None"),
	Head UMETA(DisplayName = "Head"),
	Hair UMETA(DisplayName = "Hair"),
	Chest UMETA(DisplayName = "Chest"),
	Hands UMETA(DisplayName = "Hands"),
	Shoulders UMETA(DisplayName = "Shoulders"),
	Legs UMETA(DisplayName = "Legs"),
	Feet UMETA(DisplayName = "Feet"),
	Shield UMETA(DisplayName = "Shield")
};

UENUM(BlueprintType)
enum class ENavigation : uint8
{
	Front UMETA(DisplayName = "Front"),
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right"),
	Back UMETA(DisplayName = "Back")
};

UENUM(BlueprintType)
enum class EPauseTabs : uint8
{
	PauseMenu UMETA(DisplayName = "Pause Menu"),
	Inventory UMETA(DisplayName = "Inventory Menu"),
	Map UMETA(DisplayName = "Map"),
	Faction UMETA(DisplayName = "Factions"),
	Character UMETA(DisplayName = "Character")
};

UENUM(BlueprintType)
enum class ECurrentCharacterPart : uint8
{
	None UMETA(DisplayName = "None"),
	Face UMETA(DisplayName = "Face"),
	Torso UMETA(DisplayName = "Torso"),
	Legs UMETA(DisplayName = "Legs"),
	Feet UMETA(DisplayName = "Feet"),
	Hair UMETA(DisplayName = "Hair"),
	Eyebrows UMETA(DisplayName = "Eyebrows"),
	Mustache UMETA(DisplayName = "Mustache"),
	Beard UMETA(DisplayName = "Beard")
};

UENUM(BlueprintType)
enum class ESelectedHeight : uint8
{
	Short UMETA(DisplayName = "Short"),
	Medium UMETA(DisplayName = "Medium"),
	Tall UMETA(DisplayName = "Tall")
};

UENUM(BlueprintType)
enum class ESelectedWeight : uint8
{
	Underweight UMETA(DisplayName = "Underweight"),
	Normal UMETA(DisplayName = "Normal Weight"),
	Overweight UMETA(DisplayName = "Overweight")
};

UENUM(BlueprintType)
enum class EBowSoundType : uint8
{
	Draw UMETA(DisplayName = "Draw"),
	Release UMETA(DisplayName = "Release"),
	Fire UMETA(DisplayName = "Fire")
};

UENUM(BlueprintType)
enum class EAttackResult : uint8
{
	Success UMETA(DisplayName = "Success"),
	Failed UMETA(DisplayName = "Failed"),
	Parried UMETA(DisplayName = "Parried"),
	Blocked UMETA(DisplayName = "Blocked")
};

UENUM(BlueprintType)
enum class EEffinAbilityInputID : uint8
{
	None UMETA(DisplayName = "None"),
	Confirm UMETA(DisplayName = "Confirm"),
	Cancel UMETA(DisplayName = "Cancel"),
	LightAttack UMETA(DisplayName = "LightAttack"),
	HeavyAttack UMETA(DisplayName = "HeavyAttack"),
	Parry UMETA(DisplayName = "Parry")
};