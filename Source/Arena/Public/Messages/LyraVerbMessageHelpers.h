// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LyraVerbMessage.h"
#include "GameplayEffectTypes.h"

#include "LyraVerbMessageHelpers.generated.h"

class APlayerState;
class APlayerController;
struct FGameplayCueParameters;


UCLASS()
class ARENA_API ULyraVerbMessageHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Arena")
	static APlayerState* GetPlayerStateFromObject(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "Arena")
	static APlayerController* GetPlayerControllerFromObject(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "Arena")
	static FGameplayCueParameters VerbMessageToCueParameters(const FLyraVerbMessage& Message);

	UFUNCTION(BlueprintCallable, Category = "Arena")
	static FLyraVerbMessage CueParametersToVerbMessage(const FGameplayCueParameters& Params);
};
