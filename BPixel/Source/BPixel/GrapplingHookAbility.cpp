// Fill out your copyright notice in the Description page of Project Settings.


#include "GrapplingHookAbility.h"

#include "BPixelCharacter.h"

void UGrapplingHookAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	OwnerActor = ActorInfo->OwnerActor.Get();
	ActorInfo->OwnerActor->GetWorld()->GetTimerManager().SetTimer(GrapplePointTargetFindingHandle, this, &UGrapplingHookAbility::UpdateGrapplePointTargetFinding, 0.1f, true, -1);
	ActorInfo->OwnerActor->OnEndPlay.AddDynamic(this, &UGrapplingHookAbility::OnOwnerEndPlay);
}

AActor* UGrapplingHookAbility::ViableTargetInSight() const
{
	FHitResult HitResult;
	APlayerController* PlayerController = Cast<APlayerController>(BPCharacter->Controller);
	FCollisionQueryParams  COQP;
	COQP.AddIgnoredActor(BPCharacter);
	bool HasHit = BPCharacter->GetWorld()->LineTraceSingleByChannel(HitResult, PlayerController->PlayerCameraManager->GetCameraLocation(), PlayerController->PlayerCameraManager->GetCameraLocation() + PlayerController->PlayerCameraManager->GetCameraRotation().Vector() * GrapplingHookDistance, ECC_Visibility, COQP);

	if (HasHit && HitResult.IsValidBlockingHit())
	{
		AActor* Target = HitResult.GetActor();

		if (Target->Tags.Contains("GrappleAttachPoint"))
		{
			return Target;
		}
	}

	return nullptr;
}

void UGrapplingHookAbility::UpdateGrapplePointTargetFinding()
{
	if (!BPCharacter)
	{
		BPCharacter = Cast<ABPixelCharacter>(OwnerActor);
	}
	
	if (ViableTargetInSight())
	{
		BPCharacter->AddInteractionMode(EInteractionModeFlags::GrapplingReady);
	}
	else
	{
		BPCharacter->RemoveInteractionMode(EInteractionModeFlags::GrapplingReady);
	}
}

void UGrapplingHookAbility::OnOwnerEndPlay(AActor* ActorThatEnded, EEndPlayReason::Type Reason)
{
	BPCharacter = nullptr;
	ActorThatEnded->GetWorld()->GetTimerManager().ClearTimer(GrapplePointTargetFindingHandle);
}

void UGrapplingHookAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                            const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                            const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!BPCharacter)
	{
		BPCharacter = Cast<ABPixelCharacter>(ActorInfo->OwnerActor.Get());
	}

	if (AActor* Target = ViableTargetInSight())
	{
		CharacterMovement->StartGrapple(Target->GetActorLocation(), GrapplingForce, GrapplingReachDistance);
		UE_LOG(LogTemp, Warning, TEXT("Grappling Hook Started"));
		return;
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
