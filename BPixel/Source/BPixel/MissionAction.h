// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MissionActionDataAsset.h"
#include "MissionAction.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class BPIXEL_API UMissionAction : public UObject
{
	GENERATED_BODY()

public:
	UMissionAction();

	virtual void DoAction();
	virtual void Initialize(UMissionActionDataAsset* MissionActionData);
};