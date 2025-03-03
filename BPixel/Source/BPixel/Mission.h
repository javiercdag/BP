// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MissionAction.h"
#include "Mission.generated.h"

/**
 * 
 */

UENUM()
enum class EMissionEndType : uint8
{
	MissionEndType_None,
	MissionEndType_Success,
	MissionEndType_Failure
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMissionEnded, UMission*, Mission, EMissionEndType, MissionEndReason);

UCLASS(Abstract)
class BPIXEL_API UMission : public UObject
{
	GENERATED_BODY()

public:
	TArray<TSubclassOf<UMissionAction>> PreMissionStartActions;
	TArray<TSubclassOf<UMissionAction>> PostMissionStartActions;
	TArray<TSubclassOf<UMissionAction>> PreMissionEndActions;
	TArray<TSubclassOf<UMissionAction>> PostMissionEndActions;
	
	UMission();

	void StartMission();
	void EndMission(const EMissionEndType Reason);

	FOnMissionEnded OnMissionEnded;

protected:
	virtual void OnMissionStart();
	virtual void OnMissionEnd();
	
private:
	void RunActions(TArray<TSubclassOf<UMissionAction>> Actions);
};


