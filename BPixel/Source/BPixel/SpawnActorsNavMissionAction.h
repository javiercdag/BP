// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MissionAction.h"
#include "SpawnActorsNavMissionAction.generated.h"

/**
 * 
 */
UCLASS()
class BPIXEL_API USpawnActorsNavMissionAction : public UMissionAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int ActorCount;
	
	virtual void DoAction() override;
};
