// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BPCharacterMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BPIXEL_API UBPCharacterMovement : public UCharacterMovementComponent
{
	GENERATED_BODY()
	bool IsGrappling = false;
	FVector GrapplingDestination;
	float GrapplingForce;
	float SquaredGrapplingReachDistance;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	float SprintSpeed = 1000.f;
	
	// Sets default values for this component's properties
	UBPCharacterMovement();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void StartSprint();
	void EndSprint();
	void StartGrapple(const FVector& Destination, const float Force, const float ReachDistance);
	void EndGrapple();
};
