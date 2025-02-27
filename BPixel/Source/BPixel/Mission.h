// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mission.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class BPIXEL_API UMission : public UObject
{
	GENERATED_BODY()

	public:
	virtual void StartMission();
};
