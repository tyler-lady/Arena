// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SavedGameStructs.generated.h"

/**
 * Saved Game Library of structs
 */

USTRUCT(BlueprintType)
struct FSavedSlotInfo
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Slot")
	FString SlotName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Slot")
	FDateTime DateTime;
};

USTRUCT(BlueprintType)
struct FSavedPlayerLevel
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	int32 PlayerLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	float CurrentXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	float TotalXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	float NeededXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	float NeededXPMultiplier;
};

USTRUCT(BlueprintType)
struct FSavedPlayerInfo
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	FTransform PlayerTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	FRotator ControlRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SavedGame|Player")
	FSavedPlayerLevel PlayerLevel;
};
