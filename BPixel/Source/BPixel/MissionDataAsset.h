// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MissionActionDataAsset.h"
#include "Engine/DataAsset.h"
#include "MissionDataAsset.generated.h"

class UMission;
/**
 * 
 */
UCLASS()
class BPIXEL_API UMissionDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	TSubclassOf<UMission> MissionClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	TArray<UMissionActionDataAsset*> PreMissionStartActions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	TArray<UMissionActionDataAsset*> PostMissionStartActions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	TArray<UMissionActionDataAsset*> PreMissionEndActions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	TArray<UMissionActionDataAsset*> PostMissionEndActions;
};
