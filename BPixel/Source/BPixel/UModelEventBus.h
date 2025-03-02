// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageReceiver.h"
#include "UModelEventBus.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetSpawnedEvent, UDamageReceiver*, TargetDamageReceiver);

UCLASS()
class BPIXEL_API UModelEventBus final : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	UModelEventBus();

	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = Channels)
	FOnTargetSpawnedEvent TargetSpawned;
};


