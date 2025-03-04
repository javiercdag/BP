// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MissionActionDataAsset.h"
#include "SpawnNavMeshMissionAcDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BPIXEL_API USpawnNavMeshMissionAcDataAsset : public UMissionActionDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	int ActorCount;
};
