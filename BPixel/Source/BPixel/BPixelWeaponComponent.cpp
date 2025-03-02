// Copyright Epic Games, Inc. All Rights Reserved.


#include "BPixelWeaponComponent.h"
#include "BPixelCharacter.h"
#include "BPixelProjectile.h"
#include "DamageReceiver.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ViewEventBus.h"
#include "Animation/AnimInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UBPixelWeaponComponent::UBPixelWeaponComponent()
{
	// Default offset from the character location for projectiles to spawn
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
	BulletsLeftInMagazine = MaxMagazineSize;
}

void UBPixelWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!AttachWeaponHandle.IsValid())
	{
		GetWorld()->GetTimerManager().SetTimer(AttachWeaponHandle, this, &UBPixelWeaponComponent::AttachWeaponPlayerDelayed, 1.f, false, -1);
	}
}

void UBPixelWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(FireMappingContext);
		}
	}

	// maintain the EndPlay call chain
	Super::EndPlay(EndPlayReason);
}

void UBPixelWeaponComponent::Fire()
{
	if (!Character || !PlayerController)
	{
		return;
	}

	if (!AutoFireHandle.IsValid())
	{
		FireSingleShot();
		GetWorld()->GetTimerManager().SetTimer(AutoFireHandle, this, &UBPixelWeaponComponent::FireSingleShot, 60/FireRate, true, -1);
		UE_LOG(LogTemp, Warning, TEXT("Fire weapon"));
	}
}

void UBPixelWeaponComponent::EndFire()
{
	if (AutoFireHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(AutoFireHandle);
		UE_LOG(LogTemp, Warning, TEXT("Stop fire weapon"));
	}
}

void UBPixelWeaponComponent::FireSingleShot()
{
	// Try and fire a projectile
	if (ProjectileClass && BulletsLeftInMagazine > 0)
	{
		UWorld* const World = GetWorld();
		
		if (World != nullptr)
		{
			FHitResult HitResult;
			FCollisionQueryParams  COQP;
			COQP.AddIgnoredActor(Character);
			bool HasHit = GetWorld()->LineTraceSingleByChannel(HitResult, PlayerController->PlayerCameraManager->GetCameraLocation(), PlayerController->PlayerCameraManager->GetCameraLocation() + PlayerController->PlayerCameraManager->GetCameraRotation().Vector() * Range, ECC_Visibility, COQP);

			if (HasHit && HitResult.IsValidBlockingHit())
			{
				UE_LOG(LogTemp, Warning, TEXT("Shot Hit Something"));
				AActor* Actor = HitResult.GetActor();

				if (UDamageReceiver* DamageReceiver = Actor->FindComponentByClass<UDamageReceiver>())
				{
					DamageReceiver->ApplyHitDamage(Damage);
				}
			}

			BulletsLeftInMagazine--;

			if (BulletsLeftInMagazine <= 0 && !ReloadHandle.IsValid())
			{
				UE_LOG(LogTemp, Warning, TEXT("Reloading..."));
				GetWorld()->GetTimerManager().SetTimer(ReloadHandle, this, &UBPixelWeaponComponent::Reload, ReloadSeconds, false, -1);
				WeaponReloadStarted.Broadcast();
			}

			// Try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation(), 0.25f, 1.f, 0, nullptr);
			}
		}
	}
}

void UBPixelWeaponComponent::Reload()
{
	BulletsLeftInMagazine = MaxMagazineSize;
	GetWorld()->GetTimerManager().ClearTimer(ReloadHandle);
	WeaponReloadEnded.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Reload finished"));
}

bool UBPixelWeaponComponent::AttachWeapon(ABPixelCharacter* TargetCharacter)
{
	Character = TargetCharacter;
	PlayerController = Cast<APlayerController>(Character->GetController());

	// Check that the character is valid, and has no weapon component yet
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<UBPixelWeaponComponent>())
	{
		return false;
	}

	// Attach the weapon to the First Person Character
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));

	// Set up action bindings
	if (PlayerController)
	{
		if (UViewEventBus* ViewEventBus = GetWorld()->GetGameInstance()->GetSubsystem<UViewEventBus>())
		{
			ViewEventBus->PlayerWeaponEquipped.Broadcast(this);
		}
		
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Set the priority of the mapping to 1, so that it overrides the Jump action with the Fire action when using touch input
			Subsystem->AddMappingContext(FireMappingContext, 1);
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			// Fire
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &UBPixelWeaponComponent::Fire);
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &UBPixelWeaponComponent::EndFire);
		}
	}

	return true;
}

void UBPixelWeaponComponent::AttachWeaponPlayerDelayed()
{
	AttachWeapon(Cast<ABPixelCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter()));
	GetWorld()->GetTimerManager().ClearTimer(AttachWeaponHandle);
}
