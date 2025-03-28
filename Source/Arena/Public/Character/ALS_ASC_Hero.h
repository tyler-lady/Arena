// Copyright Tyler Lady

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "ALS_ASC_Hero.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API AALS_ASC_Hero : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AALS_ASC_Hero(const FObjectInitializer& ObjectInitializer);

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */

private:
	virtual void InitAbilityActorInfo() override;
};
