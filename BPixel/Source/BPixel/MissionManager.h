// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mission.h"
#include "MissionDataAsset.h"
#include "GameFramework/Actor.h"
#include "MissionManager.generated.h"

UCLASS()
class BPIXEL_API AMissionManager : public AActor
{
	GENERATED_BODY()
	TArray<UMission*> Missions;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "Missions")
	TArray<UMissionDataAsset*> MissionDefinitions;
	// Sets default values for this actor's properties
	AMissionManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	void StartMission(int MissionIndex);

public:
	UFUNCTION()
	void OnMissionEnded(UMission* Mission, EMissionEndType Reason);
};
