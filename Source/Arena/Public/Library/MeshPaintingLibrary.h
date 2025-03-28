// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MeshPaintingLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UMeshPaintingLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static FTransform GetWorldSpaceTransform(FReferenceSkeleton RefSkel, int32 BoneIdx);

	UFUNCTION(BlueprintCallable, Category = "BPLibrary")
	static FTransform GetRefPoseBoneTransform(USkeletalMeshComponent* SkelMesh, FName BoneName);

	UFUNCTION(BlueprintCallable, Category = "BPLibrary")
	static FTransform GetBoneTransform(USkeletalMeshComponent* SkelMesh, FName BoneName);
};
