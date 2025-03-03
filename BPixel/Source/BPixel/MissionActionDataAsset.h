// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MissionAction.h"
#include "Engine/DataAsset.h"
#include "MissionActionDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BPIXEL_API UMissionActionDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	TSubclassOf<UMissionAction> MissionActionClass;
};
