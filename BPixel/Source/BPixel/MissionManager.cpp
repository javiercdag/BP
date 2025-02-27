// Fill out your copyright notice in the Description page of Project Settings.


#include "MissionManager.h"

// Sets default values
AMissionManager::AMissionManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
			UMission* MissionInstance = NewObject<UMission>(this, MissionDefinitions[i]);
			Missions.Add(MissionInstance);
		}
		
		Missions[0]->StartMission();
	}
}

// Called every frame
void AMissionManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

