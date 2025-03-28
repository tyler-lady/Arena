// Copyright:       Copyright (C) 2022 Doğa Can Yanıkoğlu
// Source Code:     https://github.com/dyanikoglu/ALS-Community


#pragma once

#include "CoreMinimal.h"
#include "Perception/AISightTargetInterface.h"
#include "Library/AI_StructLibrary.h"
#include "Character/ALSBaseCharacter.h"
#include "ALSCharacter.generated.h"

/**
 * Specialized character class, with additional features like held object etc.
 */
UCLASS(Blueprintable, BlueprintType)
class ALSV4_CPP_API AALSCharacter : public AALSBaseCharacter, public IAISightTargetInterface
{
	GENERATED_BODY()

public:
	AALSCharacter(const FObjectInitializer& ObjectInitializer);

	/** Implemented on BP to update held objects */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "ALS|HeldObject")
	void UpdateHeldObject();

	UFUNCTION(BlueprintCallable, Category = "ALS|HeldObject")
	void ClearHeldObject();

	UFUNCTION(BlueprintCallable, Category = "ALS|HeldObject")
	void AttachToHand(UStaticMesh* NewStaticMesh, USkeletalMesh* NewSkeletalMesh,
	                  class UClass* NewAnimClass, bool bLeftHand, FVector Offset);

	virtual void RagdollStart() override;

	virtual void RagdollEnd() override;

	virtual ECollisionChannel GetThirdPersonTraceParams(FVector& TraceOrigin, float& TraceRadius) override;

	virtual FTransform GetThirdPersonPivotTarget() override;

	virtual FVector GetFirstPersonCameraTarget() override;

	virtual bool CanBeSeenFrom(const FVector& ObserverLocation, FVector& OutSeenLocation, int32& NumberOfLoSChecksPerformed, float& OutSightStrength, const AActor* IgnoreActor = nullptr, const bool* bWasVisible = nullptr, int32* UserData = nullptr) const override;

protected:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void OnOverlayStateChanged(EALSOverlayState PreviousState) override;
	
	/** Implement on BP to update animation states of held objects */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "ALS|HeldObject")
	void UpdateHeldObjectAnimations();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &) const override;

public:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "ALS|AI")
	FAI_GroupMemberDetails NPCStruct;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Component")
	TObjectPtr<USceneComponent> HeldObjectRoot = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Component")
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS|Component")
	TObjectPtr<UStaticMeshComponent> StaticMesh = nullptr;
	
private:
	bool bNeedsColorReset = false;
};
