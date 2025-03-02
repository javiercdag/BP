// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovementAbility.h"
#include "GrapplingHookAbility.generated.h"

/**
 * 
 */
UCLASS()
class BPIXEL_API UGrapplingHookAbility : public UMovementAbility
{
	GENERATED_BODY()
	FTimerHandle GrapplePointTargetFindingHandle;
	AActor* OwnerActor;
	ABPixelCharacter* BPCharacter;
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	AActor* ViableTargetInSight() const;
	void UpdateGrapplePointTargetFinding();
	
	UFUNCTION()
	void OnOwnerEndPlay(AActor* Actor, EEndPlayReason::Type Reason);
	
public:
	UPROPERTY(BlueprintReadOnly)
	float GrapplingHookDistance = 5000.f;
	float GrapplingForce = 500.f;
	float GrapplingReachDistance = 500.f;
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
};
