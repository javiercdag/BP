// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintAbility.h"

void USprintAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	CharacterMovement->StartSprint();
	UE_LOG(LogTemp, Warning, TEXT("Sprint Started"));
}

void USprintAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	CharacterMovement->EndSprint();
	UE_LOG(LogTemp, Warning, TEXT("Sprint Ended"));
}
