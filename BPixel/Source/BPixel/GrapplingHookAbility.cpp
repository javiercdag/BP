// Fill out your copyright notice in the Description page of Project Settings.


#include "GrapplingHookAbility.h"

#include "BPixelCharacter.h"

void UGrapplingHookAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                            const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                            const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	FHitResult HitResult;
	ABPixelCharacter* Character = Cast<ABPixelCharacter>(CharacterMovement->GetCharacterOwner());
	APlayerController* PlayerController = Cast<APlayerController>(Character->Controller);
	FCollisionQueryParams  COQP;
	COQP.AddIgnoredActor(Character);
	bool HasHit = GetWorld()->LineTraceSingleByChannel(HitResult, PlayerController->PlayerCameraManager->GetCameraLocation(), PlayerController->PlayerCameraManager->GetCameraLocation() + PlayerController->PlayerCameraManager->GetCameraRotation().Vector() * GrapplingHookDistance, ECC_Visibility, COQP);

	if (HasHit && HitResult.IsValidBlockingHit())
	{
		UE_LOG(LogTemp, Warning, TEXT("Grappling Hook Hit Something"));
		AActor* Actor = HitResult.GetActor();

		if (Actor->Tags.Contains("GrappleAttachPoint"))
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Grappling Hook Attach Point"));
			CharacterMovement->StartGrapple(Actor->GetActorLocation(), GrapplingForce, GrapplingReachDistance);
			UE_LOG(LogTemp, Warning, TEXT("Grappling Hook Started"));
			return;
		}
	}
	
	EndAbility(Handle, ActorInfo, ActivationInfo, false, true);
}

void UGrapplingHookAbility::EndAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	CharacterMovement->EndGrapple();
	UE_LOG(LogTemp, Warning, TEXT("Grappling Hook Ended"));
}
