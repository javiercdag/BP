// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UMission();

	virtual void StartMission();
	virtual void EndMission(const EMissionEndType Reason);

	FOnMissionEnded OnMissionEnded;
};


