// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BPixelAbilitySystemComponent.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class AbilityInputID : uint8
{
	None UMETA(DisplayName = "None"),
	Confirm UMETA(DisplayName = "Confirm"),
	Cancel UMETA(DisplayName = "Cancel")
};

UCLASS()
class BPIXEL_API UBPixelAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> Abilities;
};
