// Fill out your copyright notice in the Description page of Project Settings.


#include "RoamingAIController.h"

#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"
#include "Navigation/PathFollowingComponent.h"

void ARoamingAIController::BeginPlay()
{
	Super::BeginPlay();

	// const UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	//
	// FNavLocation RandomNavLocation;
	// NavSys->GetRandomPointInNavigableRadius(GetOwner()->GetActorLocation(), MaxSearchRange, RandomNavLocation);
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	FVector Target = FVector(2010.000000,1360.000000,90.000000);
	
	if (NavSys != nullptr)
	{
		FNavLocation ProjectedLocation;
		NavSys->ProjectPointToNavigation(Target, ProjectedLocation, FVector(500.0f, 500.0f, 300.0f));
		Target = ProjectedLocation.Location;
	}
	
	FAIMoveRequest MoveRequest;
	MoveRequest.SetGoalLocation(Target);

	FPathFollowingRequestResult MoveResult = MoveTo(MoveRequest, nullptr);
	
	if (GEngine)
	{
		if (MoveResult == EPathFollowingRequestResult::Type::RequestSuccessful)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("AI Move Request Successful"));
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("FAILED - AI Move Request"));
		}
	}
}

void ARoamingAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	Super::OnMoveCompleted(RequestID, Result);
}
