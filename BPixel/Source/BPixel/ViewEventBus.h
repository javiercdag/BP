// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BPixelWeaponComponent.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ViewEventBus.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponEquipped, UBPixelWeaponComponent*, Weapon);

UCLASS()
class BPIXEL_API UViewEventBus : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UViewEventBus();

public:
	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = Channels)
	FOnWeaponEquipped PlayerWeaponEquipped;
};
