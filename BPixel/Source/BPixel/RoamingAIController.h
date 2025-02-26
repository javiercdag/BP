// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "RoamingAIController.generated.h"

/**
 * 
 */
UCLASS()
class BPIXEL_API ARoamingAIController : public AAIController
{
	GENERATED_BODY()

	void TryStartRandomRoam();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;

	protected:
	UPROPERTY(Category="Movement", EditAnywhere, BlueprintReadWrite)
	float MaxSearchRange = 1000.f;

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
};
