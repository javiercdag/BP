// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionManager.h"

// Sets default values
AMissionManager::AMissionManager()
{
}


// Called when the game starts or when spawned
void AMissionManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMissionManager::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	if (!MissionDefinitions.IsEmpty())
	{
		for (int i = 0; i < MissionDefinitions.Num(); i++)
		{
			UMission* MissionInstance = NewObject<UMission>(this, MissionDefinitions[i]->MissionClass);
			MissionInstance->Initialize(MissionDefinitions[i]);
			Missions.Add(MissionInstance);
		}
	}
	
	StartMission(0);
}

void AMissionManager::StartMission(int MissionIndex)
{
	Missions[MissionIndex]->StartMission();
	Missions[MissionIndex]->OnMissionEnded.AddDynamic(this, &AMissionManager::OnMissionEnded);
}

void AMissionManager::OnMissionEnded(UMission* Mission, EMissionEndType Reason)
{
	Missions.Remove(Mission);

	if (Missions.Num() <= 0)
	{
		UE_LOG(LogTemp, Display, TEXT("YOU WIN!"));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("YOU WIN!!"));
	}
	else
	{
		StartMission(0);
	}
}