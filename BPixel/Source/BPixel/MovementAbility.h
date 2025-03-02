// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BPCharacterMovement.h"
#include "BPixelCharacter.h"
#include "MovementAbility.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class BPIXEL_API UMovementAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UBPCharacterMovement* CharacterMovement;
	
public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
