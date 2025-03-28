// Copyright Tyler Lady


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, const FEffectType& EffectType)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if(TargetASC == nullptr) return;
	
	//check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(EffectType.GameplayEffectClass, ActorLevel, EffectContextHandle);
	const TSharedPtr<FActiveGameplayEffectHandle> ActiveEffectHandle = MakeShared<FActiveGameplayEffectHandle>(TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data));
	
	if ( EffectSpecHandle.Data->Def->DurationPolicy == EGameplayEffectDurationType::Infinite && EffectType.EffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap )
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}
	
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	for ( auto& Effect : Effects )
	{
		if ( Effect.EffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap )
		{
			ApplyEffectToTarget(TargetActor, Effect);
		}
	}
}

void AAuraEffectActor::EndOverlap(AActor* TargetActor)
{
	for(auto& Effect : Effects)
	{
		if ( Effect.EffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
		{
			ApplyEffectToTarget(TargetActor, Effect);
		}
		else if(Effect.EffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
		{
			UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
			if(!IsValid(TargetASC)) return;

			TArray<TSharedPtr<FActiveGameplayEffectHandle>> HandlesToRemove;
			for(auto HandlePair : ActiveEffectHandles)
			{
				if(TargetASC == HandlePair.Value)
				{
					TargetASC->RemoveActiveGameplayEffect(*HandlePair.Key, 1);
					HandlesToRemove.Add(HandlePair.Key);
				}
			}
			for(auto& Handle : HandlesToRemove)
			{
				ActiveEffectHandles.FindAndRemoveChecked(Handle);
			}
		}
	}
}

