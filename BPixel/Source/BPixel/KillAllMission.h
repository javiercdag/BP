// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageReceiver.h"
#include "Mission.h"
#include "KillAllMission.generated.h"

/**
 * 
 */
UCLASS()
class BPIXEL_API UKillAllMission : public UMission
{
	GENERATED_BODY()

public:
	TArray<TWeakObjectPtr<UDamageReceiver>> Targets;

	virtual void StartMission() override;
	
	UFUNCTION()
	void OnTargetSpawned(UDamageReceiver* Target);
};
