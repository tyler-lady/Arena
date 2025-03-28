// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayEffect.h"
#include "Library/Inventory/Enums/InventoryKitEnums.h"
#include "InventoryKitStructs.generated.h"


/**
 * Inventory Kit library of structs
 */

USTRUCT(BlueprintType)
struct FBaseItemInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EItemRarity Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	int32 Required_Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UTexture2D* Icon;
};

USTRUCT(BlueprintType)
struct FItemMasterInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FBaseItemInfo BaseItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FDataTableRowHandle ItemsDataTable;
};

USTRUCT(BlueprintType)
struct FWeaponSocketInfo
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FName EquippedSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FName SecondaryUnequippedSocket;
};

USTRUCT(BlueprintType)
struct FGearMeshSetup
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FName PrimarySocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FWeaponSocketInfo WeaponSocketInfo;
};

USTRUCT(BlueprintType)
struct FGearMasterInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EBaseGearType BaseGearType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EGearType GearType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EGearCategory GearCategory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TArray<FGearMeshSetup> SkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FDataTableRowHandle GearDataTable;
};

USTRUCT(BlueprintType)
struct FPerkInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EPerkTypes PerkType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UGameplayEffect* PerkGameplayEffect;
};

USTRUCT(BlueprintType)
struct FItemEditableInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	bool IsSelectedGear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EWeaponSelectedAs WeaponSelectedAs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	int32 CurrentItemLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TArray<FPerkInfo> Perks;
};

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FItemEditableInfo EditableInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FDataTableRowHandle MasterItemDataTable;
};

USTRUCT(BlueprintType)
struct FMontageSetup
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EMontageAction Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UAnimMontage* Montage;
};

USTRUCT(BlueprintType)
struct FRequiredItemsInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FName ItemsUniqueName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	int32 RequiredAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UTexture2D* Icon;
};

USTRUCT(BlueprintType)
struct FRequiredItemsList
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TArray<FRequiredItemsInfo> RequiredItemsList;
};

USTRUCT(BlueprintType)
struct FMasterArmorInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TMap<int32, int32> ArmorByLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TMap<int32, FRequiredItemsList> UpgradeItemsByLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TMap<int32, FRequiredItemsList> EngraveItemsByPerk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UGameplayEffect* ArmorGameplayEffect;
};

USTRUCT(BlueprintType)
struct FRarityChance
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EItemRarity Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	float Weight;
};

USTRUCT(BlueprintType)
struct FSelectedWeaponInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	bool IsEquipped;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	bool AttachedToPrimarySocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	bool IsSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	EWeaponSelectedAs WeaponSelectedAs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	FGearMeshSetup MeshSetupInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TArray<FMontageSetup> Montages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	AActor* ItemReference;
};

USTRUCT(BlueprintType)
struct FMasterWeaponInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TMap<int32, int32> BaseDamageByLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TMap<int32, FRequiredItemsList> UpgradeItemsByLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TMap<int32, FRequiredItemsList> EngraveItemsByPerk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	TArray<FMontageSetup> MontageSetup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	UGameplayEffect* DamageGameplayEffect;
};

/**
 * Inventory Kit - Additional item types
 */

USTRUCT(BlueprintType)
struct FTradeGoodMasterInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	int32 ValueAsCoin;
};

USTRUCT(BlueprintType)
struct FMasterQuestItemInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	bool QuestItem;
};

USTRUCT(BlueprintType)
struct FMasterDocumentsInfo : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit")
	bool DocumentInfo;
};


/**
 * Inventory Kit - ItemToSpawn
 */

USTRUCT(BlueprintType)
struct FFullRandomItemSpawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	bool CheckItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	UDataTable* AllItemsDataTable;
};

USTRUCT(BlueprintType)
struct FRandomItemSpawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	bool RandomInSpecificItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	FFullRandomItemSpawn RandomItemToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	TArray<FDataTableRowHandle> SpecificItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	TArray<FRarityChance> RarityChance;
};

USTRUCT(BlueprintType)
struct FItemToSpawn
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	bool IsRandomItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	FRandomItemSpawn RandomItemToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryKit|Spawning")
	FDataTableRowHandle SpecificItemToSpawn;
};