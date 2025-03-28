// Copyright Tyler Lady


#include "Player/Effin_ALSPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/EnemyInterface.h"

AEffin_ALSPlayerController::AEffin_ALSPlayerController()
{
	bReplicates = true; //changes made on the server replicate down to the clients
}

void AEffin_ALSPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}


void AEffin_ALSPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if(!CursorHit.bBlockingHit) return;//How to check if we got a hit

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/*
	 * Line trace from cursor. There are several scenarios:
	 * A last ctor is null && this actor is null
	 *	-do nothing
	 * B Lastactor is null && thisactor is valid
	 *	-call highlight on thisactor
	 * C Lastactor is valid && thisactor is null
	 *	-unhighlight lastactor
	 * D both actors valid, but lastactor != thisactor
	 *	-unhighlight lastactor and highlight thisactor
	 * E both actors valid and lastactor == thisactor
	 *	-do nothing
	 */

	if(LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			ThisActor->HighlightActor();
		}
		else
		{
			
		}
	}
	else
	{
		if(ThisActor == nullptr)
		{
			LastActor->UnHighlightActor();
		}
		else
		{
			if(LastActor != ThisActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				
			}
		}
	}
}

void AEffin_ALSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AEffin_ALSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	//EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move); //Binds Move to MoveAction
}
/*
void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
*/