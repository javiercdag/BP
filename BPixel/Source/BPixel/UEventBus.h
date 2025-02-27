// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageReceiver.h"
#include "UEventBus.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetSpawnedEvent, UDamageReceiver*, TargetDamageReceiver);

UCLASS()
class BPIXEL_API UEventBus final : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	UEventBus();
	
	FOnTargetSpawnedEvent TargetSpawned;
};


