// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI_EnumLibrary.generated.h"

UENUM(BlueprintType)
enum class EAI_CombatState : uint8
{
	None UMETA(DisplayName = "None"),
	Holding UMETA(DisaplyName = "Holding"),
	Action UMETA(DisplayName = "Action"),
	Recovery UMETA(DisplayName = "Recovery")
};

UENUM(BlueprintType)
enum class EAI_CombatActionType : uint8
{
	None UMETA(DisplayName = "None"),
	LightAttack UMETA(DisplayName = "Light Attack"),
	HeavyAttack UMETA(DisplayName = "Heavy Attack"),
	Dodge UMETA(DisplayName = "Dodge"),
	Parry UMETA(DisplayName = "Parry"),
	Block UMETA(DisplayName = "Block")	
};

UENUM(BlueprintType)
enum class EAIType : uint8
{
	None UMETA(DisplayName = "None"),
	ALS_AI UMETA(DisplayName = "ALS AI"),
	CustomAI UMETA(DisplayName = "Custom AI"),
	Soldier_AI UMETA(DisplayName = "Soldier AI"),
	Trader_AI UMETA(DisplayName = "Trader AI"),
	Villager_AI UMETA(DisplayName = "Villager AI"),
	CityCitizen_AI UMETA(DisplayName = "City Citizen AI")
};

UENUM(BlueprintType)
enum class EAIState : uint8
{
	None UMETA(DisplayName = "None"),
	Idle UMETA(DisplayName = "Idle"),
	Combat UMETA(DisplayName = "Combat"),
	Guard UMETA(DisplayName = "Guard"),
	Patrol UMETA(DisplayName = "Patrol"),
	Farm UMETA(DisplayName = "Farm"),
	Shop UMETA(DisplayName = "Shop"),
	Build UMETA(DisplayName = "Build"),
	Smith UMETA(DisplayName = "Smith")
};

UENUM(BlueprintType)
enum class EAITraderType : uint8
{
	WeaponTrader UMETA(DisplayName = "Weapon Trader"),
	ArmorTrader UMETA(DisplayName = "Armor Trader"),
	GeneralTrader UMETA(DisplayName = "General Trader")
};

UENUM(BlueprintType)
enum class EAI_SoundType : uint8
{
	Footstep UMETA(DisplayName = "Footstep"),
	Combat UMETA(DisplayName = "Combat"),
	Arrow UMETA(DisplayName = "Arrow")
};
