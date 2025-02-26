// Fill out your copyright notice in the Description page of Project Settings.


#include "RoamingAIController.h"

#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"
#include "Navigation/PathFollowingComponent.h"

void ARoamingAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ARoamingAIController::BeginPlay()
{
	Super::BeginPlay();

	TryStartRandomRoam();
}

void ARoamingAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	TryStartRandomRoam();
}

void ARoamingAIController::TryStartRandomRoam()
{
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	
	if (NavSys != nullptr)
	{
		FNavLocation ProjectedLocation;
		NavSys->GetRandomReachablePointInRadius(GetPawn()->GetActorLocation(), 5000, ProjectedLocation);
		NavSys->ProjectPointToNavigation(ProjectedLocation.Location, ProjectedLocation);

		FAIMoveRequest MoveRequest;
		MoveRequest.SetGoalLocation(ProjectedLocation.Location);
		MoveTo(MoveRequest, nullptr);
	}
}
