// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CombInv_EnumLibrary.h"
//#include "GroomAsset.h"
#include "HairStrandsInterface.h"
#include "ALSV4_CPP/Public/Library/ALSAnimationStructLibrary.h"
#include "Engine/DataTable.h"
#include "CombInvStructLibrary.generated.h"

USTRUCT(BlueprintType)
struct FInventorySettings_1 : public FTableRowBase
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FText Title = Title.FromString("Inventory");

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FVector2D Item_Dimension;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 int32 Columns = 8;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 int32 Rows = 10;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool Auto_Size_Height = false;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 uint8 Item_Count_Position = 0;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool Show_All_Grid = true;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FName All_Grid_Name = TEXT("All Items");

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TArray<EItemCategory> Categories_To_Show;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UTexture2D* Empty_Slot_Icon = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool Show_Category = true;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool Show_Title = true;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool Movable = true;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FVector2D Default_Position;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UTexture2D* Main_Window = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UTexture2D* Grid_Window = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UTexture2D* Button_Select = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UTexture2D* Button_Cancel = nullptr;

 FInventorySettings_1()
 {
  Item_Dimension.Set(64.0f,64.0f);
  Categories_To_Show.Empty();
  Default_Position.Set(1000.0f,200.0f);
 }
};

USTRUCT(BlueprintType)
struct FCombatTurnInPlace
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FALSTurnInPlaceAsset Fist;
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FALSTurnInPlaceAsset Fencer;
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FALSTurnInPlaceAsset TwoHandedSword;
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FALSTurnInPlaceAsset SwordAndShield;
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FALSTurnInPlaceAsset Spear;

 FCombatTurnInPlace()
 {
  Fist.Animation = nullptr;
  Fist.AnimatedAngle = 0.0f;
  Fist.SlotName = TEXT("Combat");
  Fist.PlayRate = 1.0f;
  Fist.ScaleTurnAngle = true;
  Fencer.Animation = nullptr;
  Fencer.AnimatedAngle = 0.0f;
  Fencer.SlotName = TEXT("Combat");
  Fencer.PlayRate = 1.0f;
  Fencer.ScaleTurnAngle = true;
  TwoHandedSword.Animation = nullptr;
  TwoHandedSword.AnimatedAngle = 0.0f;
  TwoHandedSword.SlotName = TEXT("Combat");
  TwoHandedSword.PlayRate = 1.0f;
  TwoHandedSword.ScaleTurnAngle = true;
  SwordAndShield.Animation = nullptr;
  SwordAndShield.AnimatedAngle = 0.0f;
  SwordAndShield.SlotName = TEXT("Combat");
  SwordAndShield.PlayRate = 1.0f;
  SwordAndShield.ScaleTurnAngle = true;
  Spear.Animation = nullptr;
  Spear.AnimatedAngle = 0.0f;
  Spear.SlotName = TEXT("Combat");
  Spear.PlayRate = 1.0f;
  Spear.ScaleTurnAngle = true;
 }
};

USTRUCT(BlueprintType)
struct FHit_Reaction_1
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* GetHit = nullptr;
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* GetHit_1H = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* GetHit_2H = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* GetHit_Spear = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* GetHit_SnS = nullptr;
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* HetHitBow = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Parry = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Parry_1H = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Parry_2H = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Parry_Spear = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Parry_SnS = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Short_Dodge = nullptr;
};

USTRUCT(BlueprintType)
struct FDodgeAnimData
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Dodge_Back;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Dodge_Fwrd;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Dodge_Left;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Dodge_Right;
 
};

USTRUCT(BlueprintType)
struct FWeapon_Details_1
{
 GENERATED_BODY()
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FText Name = Name.FromString(TEXT(""));

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FText Description = Description.FromString(TEXT(""));

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TArray<UAnimMontage*> LightAttackMontages;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TArray<UAnimMontage*> HeavyAttackMontages;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TMap<UAnimMontage*, FHit_Reaction_1> Hit_Reactions;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FDodgeAnimData DodgeMontages;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UStaticMesh* StaticMesh = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* SkMesh = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float Damage = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float StaminaCost = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float AttackSpeed = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 EWeaponType WeaponType;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* FallingAttack = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* SprintAttack = nullptr;

 FWeapon_Details_1()
 {
  LightAttackMontages.Empty();
  HeavyAttackMontages.Empty();
  Hit_Reactions.Empty();
 }
};

USTRUCT(BlueprintType)
struct FEquipment_Details
{
 GENERATED_BODY()
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FText Name = Name.FromString(TEXT(""));

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FText Description = Description.FromString(TEXT(""));

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UStaticMesh* StaticMesh = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* SkMesh = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float Damage = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float StaminaCost = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float AttackSpeed = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 EEquipmentType EquipmentType;
 
};


USTRUCT(BlueprintType)
struct FItem_1 : public FTableRowBase
{
 GENERATED_BODY()
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FName ID = TEXT("Item Name");

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 int32 Count = 0;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool Stackable = false;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 int32 Max_Stack_Count = 0;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UTexture2D* Icon = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float Weight = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 EItemCategory Category;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool Locked = false;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TArray<EItemActions> Context_Menus;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TSubclassOf<AActor> Item;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FWeapon_Details_1 Weapon_Details;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FEquipment_Details Equipment_Details;
};

USTRUCT(BlueprintType)
struct FCounterAnimData
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* Player;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UAnimMontage* AI;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float Distance = 0.0f;
};

//Struct to track/create the details that make up a faction
USTRUCT(BlueprintType)
struct FFactionDetails : public FTableRowBase
{
 GENERATED_BODY()
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FName ID = TEXT("Faction Name");

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FText Description = FText();
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 int32 Lord_Count = 0;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UTexture2D* Icon = nullptr;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float Confidence = 0.0f;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FLinearColor FactionColor;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TSubclassOf<ACharacter> NPC_Classes;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 TSubclassOf<AActor> Lord_Classes;
};

//Struct containing all of the face material elements needed for MetaHumans
USTRUCT(BlueprintType)
struct FMH_FaceMaterials : public FTableRowBase
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element0;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element1;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element2;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element3;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element4;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element5;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element6;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element7;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element8;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element9;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element10;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element11;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element12;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element13;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element14;
};

USTRUCT(BlueprintType)
struct FMH_GroomAsset_Mats
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element0;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element1;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* Element2;
};

//Struct used for building the various grooms used for MetaHumans. Has a Groom and its BindingAsset
// USTRUCT(BlueprintType)
// struct FMH_GroomAsset
// {
//  GENERATED_BODY()
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  UGroomAsset* MH_Groom;
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  UGroomBindingAsset* MH_GroomBindingAsset;
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  FMH_GroomAsset_Mats MH_GroomAssetM;
// };

// //Struct containing all of the grooms used on MetaHuman faces
// USTRUCT(BlueprintType)
// struct FMH_FaceGrooms
// {
//  GENERATED_BODY()
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  FMH_GroomAsset MH_Hair;
//  
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  FMH_GroomAsset MH_Eyebrows;
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  FMH_GroomAsset MH_Fuzz;
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  FMH_GroomAsset MH_Eyelashes;
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  FMH_GroomAsset MH_Mustache;
//
//  UPROPERTY(EditAnywhere, BlueprintReadWrite)
//  FMH_GroomAsset MH_Beard;
// };

//Created character struct to track character parts
USTRUCT(BlueprintType)
struct FS_SavedCharacterParts : public FTableRowBase
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* Mesh;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* Face;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* Torso;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* Hands;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* Legs;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* Feet;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 USkeletalMesh* FaceAccessory;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* MeshM;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FMH_FaceMaterials FaceM;

 // UPROPERTY(EditAnywhere, BlueprintReadWrite)
 // FMH_FaceGrooms GroomAssets;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* TorsoM;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* HandsM;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* LegsM;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* FeetM;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInterface* FaceAccessoryM;
};

USTRUCT(BlueprintType)
struct FAttack_HitData
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 float Damage;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 AActor* DamageCauser;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 FVector HitFromDirection;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool CanBeParried;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool CanBeBlocked;

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 bool CanReceiveImpact;
 
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 AActor* HitActor;
 
 UPROPERTY(EditAnyWhere, BlueprintReadWrite)
 FHit_Reaction_1 HitReaction;
};
