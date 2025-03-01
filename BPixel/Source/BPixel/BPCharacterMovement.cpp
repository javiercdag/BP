// Fill out your copyright notice in the Description page of Project Settings.


#include "BPCharacterMovement.h"

#include "BPixelCharacter.h"

// Sets default values for this component's properties
UBPCharacterMovement::UBPCharacterMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UBPCharacterMovement::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsGrappling)
	{
		FVector ToDestination = GrapplingDestination - GetActorLocation();

		if (ToDestination.SquaredLength() > SquaredGrapplingReachDistance)
		{
			AddForce(ToDestination * GrapplingForce);
		}
		else
		{
			GetOwner<ABPixelCharacter>()->EndGrappling();
		}
	}
}

void UBPCharacterMovement::StartSprint()
{
	MaxWalkSpeed = SprintSpeed;
}

void UBPCharacterMovement::EndSprint()
{
	MaxWalkSpeed = GetDefault<UCharacterMovementComponent>(GetClass())->MaxWalkSpeed;
}

void UBPCharacterMovement::StartGrapple(const FVector& Destination, const float Force, const float ReachDistance)
{
	GrapplingDestination = Destination;
	IsGrappling = true;
	GravityScale = 0;
	GrapplingForce = Force;
	SquaredGrapplingReachDistance = ReachDistance * ReachDistance;
}

void UBPCharacterMovement::EndGrapple()
{
	IsGrappling = false;
	GravityScale = GetDefault<UBPCharacterMovement>(GetClass())->GravityScale;
}

