// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageReceiver.h"

// Sets default values for this component's properties
UDamageReceiver::UDamageReceiver() { }


// Called when the game starts
void UDamageReceiver::BeginPlay()
{
	Super::BeginPlay();

	HitPoints = MaxHitPoints;
}

void UDamageReceiver::ApplyHitDamage(float DamageAmount)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Damage: %f"), DamageAmount));
		HitPoints -= DamageAmount;
		
		if (HitPoints <= 0)
		{
			GetOwner()->Destroy();
		}
	}
}