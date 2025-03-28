// Copyright Tyler Lady

#pragma once

#include "CoreMinimal.h"
#include "Character/ALSPlayerController.h"
#include "GameFramework/PlayerController.h"
#include "Effin_ALSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class ARENA_API AEffin_ALSPlayerController : public AALSPlayerController
{
	GENERATED_BODY()

public:
	AEffin_ALSPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	/*
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue& InputActionValue);
	*/
	void CursorTrace();

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
	
};

