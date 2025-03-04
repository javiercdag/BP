// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActorsNavMissionAction.h"

#include "NavigationSystem.h"
#include "SpawnNavMeshMissionAcDataAsset.h"

void USpawnActorsNavMissionAction::DoAction()
{
	Super::DoAction();

	for (int i = 0; i < ActorCount; i++)
	{
		SpawnActorOnNavMesh();
	}
}

void USpawnActorsNavMissionAction::SpawnActorOnNavMesh()
{
	// Get the navigation system
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    
	if (NavSys)
	{
		FNavLocation RandomNavLocation;
		
		if (NavSys->GetRandomReachablePointInRadius(GetWorld()->GetFirstPlayerController()->GetSpawnLocation(), 10000, RandomNavLocation))
		{
			// Spawn the actor at the found location
			FActorSpawnParameters SpawnParams;
			GetWorld()->SpawnActor<AActor>(ActorClass, RandomNavLocation.Location, FRotator::ZeroRotator, SpawnParams);
		}
	}
}

void USpawnActorsNavMissionAction::Initialize(UMissionActionDataAsset* MissionActionData)
{
	Super::Initialize(MissionActionData);

	if (USpawnNavMeshMissionAcDataAsset* DataAsset = Cast<USpawnNavMeshMissionAcDataAsset>(MissionActionData))
	{
		ActorCount = DataAsset->ActorCount;
		ActorClass = DataAsset->ActorClass;
	}
}
