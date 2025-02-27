// Fill out your copyright notice in the Description page of Project Settings.


#include "KillAllMission.h"

#include "UEventBus.h"

void UKillAllMission::StartMission()
{
	Super::StartMission();
	GetWorld()->GetSubsystem<UEventBus>()->TargetSpawned.AddDynamic(this, &UKillAllMission::OnTargetSpawned);
}

void UKillAllMission::OnTargetSpawned(UDamageReceiver* Target)
{
	Targets.Add(TWeakObjectPtr(Target));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("New target registered!"));
}
