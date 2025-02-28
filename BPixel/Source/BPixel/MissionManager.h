// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mission.h"
#include "GameFramework/Actor.h"
#include "MissionManager.generated.h"

UCLASS()
class BPIXEL_API AMissionManager : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Missions")
	TArray<TSubclassOf<UMission>> MissionDefinitions;
	// Sets default values for this actor's properties
	AMissionManager();

protected:
	TArray<TWeakObjectPtr<UMission>> Missions;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	void StartMission(int MissionIndex);

public:
	UFUNCTION()
	void OnMissionEnded(UMission* Mission, EMissionEndType Reason);
};
