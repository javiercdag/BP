// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementAbility.h"

void UMovementAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	CharacterMovement = Cast<ABPixelCharacter>(ActorInfo->AvatarActor)->GetCharacterMovement<UBPCharacterMovement>();
}
