// Copyright:       Copyright (C) 2022 Doğa Can Yanıkoğlu
// Source Code:     https://github.com/dyanikoglu/ALS-Community

#include "AI/ALS_BTTask_ClearFocusFromPlayer.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AIController.h"

UALS_BTTask_ClearFocusFromPlayer::UALS_BTTask_ClearFocusFromPlayer()
{
	NodeName = "Clear Focus From Player";
}

EBTNodeResult::Type UALS_BTTask_ClearFocusFromPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetAIOwner()->ClearFocus(EAIFocusPriority::Gameplay);
	
	return EBTNodeResult::Succeeded;
}

FString UALS_BTTask_ClearFocusFromPlayer::GetStaticDescription() const
{
	return "Clear Focus from the player's pawn";
}
