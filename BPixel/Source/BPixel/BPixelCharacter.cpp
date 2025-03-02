// Copyright Epic Games, Inc. All Rights Reserved.

#include "BPixelCharacter.h"

#include "BPCharacterMovement.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GrapplingHookAbility.h"
#include "InputActionValue.h"
#include "SprintAbility.h"
#include "ViewEventBus.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ABPixelCharacter

ABPixelCharacter::ABPixelCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UBPCharacterMovement>(CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	AbilitySystem = CreateDefaultSubobject<UBPixelAbilitySystemComponent>(TEXT("AbilitySystem"));
}

void ABPixelCharacter::AddInteractionMode(EInteractionModeFlags Mode)
{
	EInteractionModeFlags PreviousInteractionMode = InteractionMode;
	InteractionMode |= Mode;
	NotifyPossibleInteractionModeChange(PreviousInteractionMode);
}

void ABPixelCharacter::RemoveInteractionMode(EInteractionModeFlags Mode)
{
	EInteractionModeFlags PreviousInteractionMode = InteractionMode;
	InteractionMode &= ~Mode;
	NotifyPossibleInteractionModeChange(PreviousInteractionMode);
}

void ABPixelCharacter::NotifyPossibleInteractionModeChange(const EInteractionModeFlags PreviousInteractionMode)
{
	if (InteractionMode != PreviousInteractionMode)
	{
		InteractionModeChanged.Broadcast(static_cast<uint8>(InteractionMode));

		if (UViewEventBus* ViewEventBus = GetWorld()->GetGameInstance()->GetSubsystem<UViewEventBus>())
		{
			ViewEventBus->InteractionModeChanged.Broadcast(static_cast<uint8>(InteractionMode));
		}
		
		UE_LOG(LogTemp, Warning, TEXT("Interaction Mode Changed"));
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void ABPixelCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ABPixelCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABPixelCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABPixelCharacter::Look);

		// Sprinting
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ABPixelCharacter::StartSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ABPixelCharacter::EndSprint);

		// Grappling
		EnhancedInputComponent->BindAction(GrapplingHookAction, ETriggerEvent::Started, this, &ABPixelCharacter::StartGrappling);
		EnhancedInputComponent->BindAction(GrapplingHookAction, ETriggerEvent::Completed, this, &ABPixelCharacter::EndGrappling);

		if (AbilitySystem)
		{
			for (const auto DefaultAbility : AbilitySystem->Abilities)
			{
				FGameplayAbilitySpecHandle AbilityHandle = AbilitySystem->GiveAbility(FGameplayAbilitySpec(DefaultAbility, 1, INDEX_NONE, this));

				UGameplayAbility* DefaultAbilityObject = DefaultAbility.GetDefaultObject();

				if (Cast<UGrapplingHookAbility>(DefaultAbilityObject))
				{
					GrapplingHookAbilityHandle = AbilityHandle;
				}
				else if (Cast<USprintAbility>(DefaultAbilityObject))
				{
					SprintAbilityHandle = AbilityHandle;
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void ABPixelCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ABPixelCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABPixelCharacter::StartSprint()
{
	AbilitySystem->TryActivateAbility(SprintAbilityHandle);
}

void ABPixelCharacter::EndSprint()
{
	AbilitySystem->CancelAbilityHandle(SprintAbilityHandle);
}

void ABPixelCharacter::StartGrappling()
{
	AbilitySystem->TryActivateAbility(GrapplingHookAbilityHandle);
}

void ABPixelCharacter::EndGrappling()
{
	AbilitySystem->CancelAbilityHandle(GrapplingHookAbilityHandle);
}

