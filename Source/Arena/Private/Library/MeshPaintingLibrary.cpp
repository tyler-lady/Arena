// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Public/Library/MeshPaintingLibrary.h"

FTransform UMeshPaintingLibrary::GetWorldSpaceTransform(FReferenceSkeleton RefSkel, int32 BoneIdx)
{
	FTransform BoneTransform;
	//The following comments are presented bug fixes
	if (BoneIdx > 0) //BoneIdx >= 0 
	{
		BoneTransform = RefSkel.GetRefBonePose()[BoneIdx];

		FMeshBoneInfo BoneInfo = RefSkel.GetRefBoneInfo()[BoneIdx];
		if (BoneInfo.ParentIndex != 0) //BoneIdx != 0 && BoneInfo.ParentIndex >= 0
		{
			BoneTransform *= GetWorldSpaceTransform(RefSkel, BoneInfo.ParentIndex);
		}
	}

	return BoneTransform;
}

FTransform UMeshPaintingLibrary::GetRefPoseBoneTransform(USkeletalMeshComponent* SkelMesh, FName BoneName)
{
	FTransform BoneTransform;

	if (SkelMesh && !BoneName.IsNone())
	{
		SkelMesh->ClearRefPoseOverride();
		FReferenceSkeleton RefSkel;
		RefSkel = SkelMesh->SkeletalMesh->GetRefSkeleton();

		BoneTransform = GetWorldSpaceTransform(RefSkel, RefSkel.FindBoneIndex(BoneName));
	}

	return BoneTransform;
}

FTransform UMeshPaintingLibrary::GetBoneTransform(USkeletalMeshComponent* SkelMesh, FName BoneName)
{
	FTransform BoneTransform;

	if (SkelMesh && !BoneName.IsNone())
	{
		FReferenceSkeleton RefSkel;
		RefSkel = SkelMesh->SkeletalMesh->GetRefSkeleton();
		BoneTransform = SkelMesh->GetBoneTransform(RefSkel.FindBoneIndex(BoneName));
	}

	return BoneTransform;
}
