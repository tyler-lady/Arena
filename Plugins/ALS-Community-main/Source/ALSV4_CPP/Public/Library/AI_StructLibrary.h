// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI_StructLibrary.generated.h"

//Struct for tracking the details of AI that have joined or been assigned to a group
USTRUCT(BlueprintType)
struct FAI_GroupMemberDetails
{
	GENERATED_BODY()
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name = TEXT("Character Name");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Faction = TEXT("Faction Name");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Confidence = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor FactionColor;
};
