// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageReceiver.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BPIXEL_API UDamageReceiver : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Category="HitPoints", EditAnywhere, BlueprintReadWrite)
	float HitPoints;
	
	// Sets default values for this component's properties
	UDamageReceiver();

protected:
	UPROPERTY(Category="HitPoints", EditAnywhere, BlueprintReadWrite)
	float MaxHitPoints = 10;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	void ApplyHitDamage(float DamageAmount);
};
