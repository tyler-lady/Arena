// Copyright:       Copyright (C) 2022 Doğa Can Yanıkoğlu
// Source Code:     https://github.com/dyanikoglu/ALS-Community

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Library/ALSAnimationStructLibrary.h"
#include "Library/ALSStructEnumLibrary.h"
#include "Animation/AnimInstanceProxy.h"
#include "Character/ALSBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "ALSCharacterAnimInstance.generated.h"

// forward declarations
class UALSDebugComponent;
class AALSBaseCharacter;
class UCurveFloat;
class UAnimSequence;
class UCurveVector;

/**
 *
 */
/*
USTRUCT(BlueprintType)
struct FALSAnimInstanceProxy : public FAnimInstanceProxy
{
	GENERATED_BODY()

	FALSAnimInstanceProxy()
	: FAnimInstanceProxy()
	 {}
	FALSAnimInstanceProxy(UAnimInstance* Instance);

	virtual void InitializeObjects(UAnimInstance* InAnimInstance) override;

	virtual void PreUpdate(UAnimInstance* InAnimInstance, float DeltaSeconds) override;

	virtual void Update(float DeltaSeconds) override;

	virtual void PostUpdate(UAnimInstance* InAnimInstance) const override;
	
public:
	UPROPERTY(Transient)
	TObjectPtr<AALSBaseCharacter> ProxyCharacter = nullptr;
	
	UPROPERTY(Transient)
	FALSAnimCharacterInformation ProxyCharacterInformation;

	UPROPERTY(Transient)
	FALSAnimGraphLayerBlending ProxyLayerBlendingValues;

	UPROPERTY(Transient)
	FALSMovementState ProxyMovementState = EALSMovementState::None;

	UPROPERTY(Transient)
	FALSMovementAction ProxyMovementAction = EALSMovementAction::None;

	UPROPERTY(Transient)
	FALSRotationMode ProxyRotationMode = EALSRotationMode::VelocityDirection;

	UPROPERTY(Transient)
	FALSGait ProxyGait = EALSGait::Walking;

	UPROPERTY(Transient)
	FALSStance ProxyStance = EALSStance::Standing;

	UPROPERTY(Transient)
	FALSOverlayState ProxyOverlayState = EALSOverlayState::Default;

	UPROPERTY(Transient)
	FALSGroundedEntryState ProxyGroundedEntryState = EALSGroundedEntryState::None;

	UPROPERTY(Transient)
	FALSAnimGraphAimingValues ProxyAimingValues;

	UPROPERTY(Transient)
	FALSAnimGraphGrounded ProxyGrounded;

	UPROPERTY(Transient)
	FALSAnimTurnInPlace ProxyTurnInPlaceValues;

	UPROPERTY(Transient)
	int32 TS_UpdateRate;

	UPROPERTY(Transient)
	USkeletalMeshComponent* TS_OwningComponent;

	
};*/

/**
 * Main anim instance class for character
 */
UCLASS(Blueprintable, BlueprintType)
class ALSV4_CPP_API UALSCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	//virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	//virtual void NativePostEvaluateAnimation() override;

	UFUNCTION(BlueprintCallable, Category = "ALS|Animation")
	void PlayTransition(const FALSDynamicMontageParams& Parameters);

	UFUNCTION(BlueprintCallable, Category = "ALS|Animation")
	void PlayTransitionChecked(const FALSDynamicMontageParams& Parameters);

	UFUNCTION(BlueprintCallable, Category = "ALS|Animation")
	void PlayDynamicTransition(float ReTriggerDelay, FALSDynamicMontageParams Parameters);

	UFUNCTION(BlueprintCallable, Category = "ALS|Event")
	void OnJumped();

	UFUNCTION(BlueprintCallable, Category = "ALS|Event")
	void OnPivot();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "ALS|Animation")
	void TurnInPlace(FRotator TargetRotation, float PlayRateScale, float StartTime, bool OverrideCurrent);

	UFUNCTION(BlueprintCallable, Category = "")
	void PlayQueuedTurnInPlaceAnimation();

	UFUNCTION(BlueprintCallable, Category = "ALS|Grounded")
	void SetRotationScale(float RotationScale)
	{
		Grounded.RotationScale = RotationScale;
	}

protected:

	UFUNCTION(BlueprintCallable, Category = "ALS|Grounded")
	void SetTrackedHipsDirection(EALSHipsDirection HipsDirection)
	{
		Grounded.TrackedHipsDirection = HipsDirection;
	}

	UFUNCTION(BlueprintCallable, Category = "ALS|Grounded")
	void SetGroundedEntryState(EALSGroundedEntryState NewState)
	{
		GroundedEntryState = NewState;
	}

	/** Enable Movement Animations if IsMoving and HasMovementInput, or if the Speed is greater than 150. */
	UFUNCTION(BlueprintCallable, Category = "ALS|Grounded")
	bool ShouldMoveCheck() const;

	/** Only perform a Rotate In Place Check if the character is Aiming or in First Person. */
	UFUNCTION(BlueprintCallable, Category = "ALS|Grounded")
	bool CanRotateInPlace() const;

	/**
	 * Only perform a Turn In Place check if the character is looking toward the camera in Third Person,
	 * and if the "Enable Transition" curve is fully weighted. The Enable_Transition curve is modified within certain
	 * states of the AnimBP so that the character can only turn while in those states..
	 */
	UFUNCTION(BlueprintCallable, Category = "ALS|Grounded")
	bool CanTurnInPlace() const;

	/**
	 * Only perform a Dynamic Transition check if the "Enable Transition" curve is fully weighted.
	 * The Enable_Transition curve is modified within certain states of the AnimBP so
	 * that the character can only transition while in those states.
	 */
	UFUNCTION(BlueprintCallable, Category = "ALS|Grounded")
	bool CanDynamicTransition() const;

private:

	//Thread Safe Proxy
	/*
	UPROPERTY(Transient, BlueprintReadOnly, Category = "ALS|ThreadSafe", meta = (AllowPrivateAccess = "true"))
	FALSAnimInstanceProxy Proxy;

	virtual FAnimInstanceProxy* CreateAnimInstanceProxy() override { return &Proxy; }

	virtual void DestroyAnimInstanceProxy(FAnimInstanceProxy* InProxy) override {}

	friend struct FALSAnimInstanceProxy;
	*/
	void PlayDynamicTransitionDelay();

	void OnJumpedDelay();

	void OnPivotDelay();

	/** Update Values */

	void UpdateAimingValues(float DeltaSeconds);

	void UpdateLayerValues();

	void UpdateFootIK(float DeltaSeconds);

	void UpdateMovementValues(float DeltaSeconds);

	void UpdateRotationValues();

	void UpdateInAirValues(float DeltaSeconds);

	void UpdateRagdollValues();

	/** Foot IK */

	void SetFootLocking(float DeltaSeconds, FName EnableFootIKCurve, FName FootLockCurve, FName IKFootBone,
                          float& CurFootLockAlpha, bool& UseFootLockCurve,
                          FVector& CurFootLockLoc, FRotator& CurFootLockRot);

	void SetFootLockOffsets(float DeltaSeconds, FVector& LocalLoc, FRotator& LocalRot);

	void SetPelvisIKOffset(float DeltaSeconds, FVector FootOffsetLTarget, FVector FootOffsetRTarget);

	void ResetIKOffsets(float DeltaSeconds);

	void SetFootOffsets(float DeltaSeconds, FName EnableFootIKCurve, FName IKFootBone, FName RootBone,
                          FVector& CurLocationTarget, FVector& CurLocationOffset, FRotator& CurRotationOffset);

	/** Grounded */

	void RotateInPlaceCheck();

	void TurnInPlaceCheck(float DeltaSeconds);

	void DynamicTransitionCheck();

	FALSVelocityBlend CalculateVelocityBlend() const;

	

	/** Movement */

	FVector CalculateRelativeAccelerationAmount() const;

	float CalculateStrideBlend() const;

	float CalculateWalkRunBlend() const;

	float CalculateStandingPlayRate() const;

	float CalculateDiagonalScaleAmount() const;

	float CalculateCrouchingPlayRate() const;

	float CalculateLandPrediction() const;

	FALSLeanAmount CalculateAirLeanAmount() const;

	EALSMovementDirection CalculateMovementDirection() const;

	/** Util */

	float GetAnimCurveClamped(const FName& Name, float Bias, float ClampMin, float ClampMax) const;

public:
	/** References */
	UPROPERTY(BlueprintReadOnly, Category = "Read Only Data|Character Information")
	TObjectPtr<AALSBaseCharacter> Character = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "MetaHuman")
	bool IsCustomSkeleton = false;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="MetaHuman")
	FName NAME_VB_ik_foot_l = TEXT("VB ik_foot_l");

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="MetaHuman")
	FName NAME_VB_ik_foot_r = TEXT("VB ik_foot_r");

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="MetaHuman")
	FName NAME_ik_foot_l = TEXT("ik_foot_l");

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="MetaHuman")
	FName NAME_ik_foot_r = TEXT("ik_foot_r");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Mount")
	bool IsRider = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ALS|Turn In Place")
	FALSQueuedTurnInPlace QueuedTurnInPlace;

	/** Character Information */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Character Information", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimCharacterInformation CharacterInformation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Character Information")
	FALSMovementState MovementState = EALSMovementState::None;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Character Information")
	FALSMovementAction MovementAction = EALSMovementAction::None;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Character Information")
	FALSRotationMode RotationMode = EALSRotationMode::VelocityDirection;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Character Information")
	FALSGait Gait = EALSGait::Walking;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Character Information")
	FALSStance Stance = EALSStance::Standing;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Character Information")
	FALSOverlayState OverlayState = EALSOverlayState::Default;

	/** Anim Graph - Grounded */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Grounded", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimGraphGrounded Grounded;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Grounded")
	FALSVelocityBlend VelocityBlend;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Grounded")
	FALSLeanAmount LeanAmount;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Grounded")
	FVector RelativeAccelerationAmount = FVector::ZeroVector;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Grounded")
	FALSGroundedEntryState GroundedEntryState = EALSGroundedEntryState::None;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Grounded")
	FALSMovementDirection MovementDirection = EALSMovementDirection::Forward;

	/** Anim Graph - In Air */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - In Air", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimGraphInAir InAir;

	/** Anim Graph - Aiming Values */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Aiming Values", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimGraphAimingValues AimingValues;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Aiming Values")
	FVector2D SmoothedAimingAngle = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AimingValues")
	FRotator AdditionalAimOffset;

	/** Anim Graph - Ragdoll */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Ragdoll")
	float FlailRate = 0.0f;

	/** Anim Graph - Layer Blending */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Layer Blending", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimGraphLayerBlending LayerBlendingValues;

	/** Anim Graph - Foot IK */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Foot IK", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimGraphFootIK FootIKValues;

	/** Turn In Place */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Turn In Place", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimTurnInPlace TurnInPlaceValues;

	/** Rotate In Place */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Rotate In Place", Meta = (
		    ShowOnlyInnerProperties))
	FALSAnimRotateInPlace RotateInPlace;

	/** Configuration */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Main Configuration", Meta = (
		ShowOnlyInnerProperties))
	FALSAnimConfiguration Config;

	/** Blend Curves */

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveFloat> DiagonalScaleAmountCurve = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveFloat> StrideBlend_N_Walk = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveFloat> StrideBlend_N_Run = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveFloat> StrideBlend_C_Walk = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveFloat> LandPredictionCurve = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveFloat> LeanInAirCurve = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveVector> YawOffset_FB = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Blend Curves")
	TObjectPtr<UCurveVector> YawOffset_LR = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Dynamic Transition")
	TObjectPtr<UAnimSequenceBase> TransitionAnim_R = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Dynamic Transition")
	TObjectPtr<UAnimSequenceBase> TransitionAnim_L = nullptr;

	/** IK Bone Names */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Anim Graph - Foot IK")
	FName IkFootL_BoneName = FName(TEXT("ik_foot_l"));

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Anim Graph - Foot IK")
	FName IkFootR_BoneName = FName(TEXT("ik_foot_r"));

private:
	FTimerHandle OnPivotTimer;

	FTimerHandle PlayDynamicTransitionTimer;

	FTimerHandle OnJumpedTimer;

	bool bCanPlayDynamicTransition = true;

	UPROPERTY()
	TObjectPtr<UALSDebugComponent> ALSDebugComponent = nullptr;
};
