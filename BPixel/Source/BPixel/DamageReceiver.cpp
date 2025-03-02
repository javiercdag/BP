// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageReceiver.h"

#include "UModelEventBus.h"

// Sets default values for this component's properties
UDamageReceiver::UDamageReceiver() { }


// Called when the game starts
void UDamageReceiver::BeginPlay()
{
	Super::BeginPlay();

	HitPoints = MaxHitPoints;

	GetWorld()->GetSubsystem<UModelEventBus>()->TargetSpawned.Broadcast(this);
}

void UDamageReceiver::ApplyHitDamage(float DamageAmount)
{
	if (GEngine)
	{
		UE_LOG(LogTemp, Display, TEXT("Damage Received"));
		HitPoints -= DamageAmount;
		
		if (HitPoints <= 0)
		{
			GetOwner()->Destroy();
		}
	}
}