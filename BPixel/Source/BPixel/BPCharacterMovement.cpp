// Fill out your copyright notice in the Description page of Project Settings.


#include "BPCharacterMovement.h"

// Sets default values for this component's properties
UBPCharacterMovement::UBPCharacterMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UBPCharacterMovement::StartSprint()
{
	MaxWalkSpeed = SprintSpeed;
}

void UBPCharacterMovement::EndSprint()
{
	MaxWalkSpeed = GetDefault<UCharacterMovementComponent>(GetClass())->MaxWalkSpeed;
}

