// Fill out your copyright notice in the Description page of Project Settings.


#include "KillAllMission.h"

#include "UModelEventBus.h"

void UKillAllMission::StartMission()
{
	Super::StartMission();
	GetWorld()->GetSubsystem<UModelEventBus>()->TargetSpawned.AddDynamic(this, &UKillAllMission::OnTargetSpawned);
}

void UKillAllMission::OnTargetSpawned(UDamageReceiver* Target)
{
	Targets.Add(TWeakObjectPtr(Target));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("New target registered!"));
	Target->GetOwner()->OnDestroyed.AddDynamic(this, &UKillAllMission::OnTargetKilled);
}

void UKillAllMission::OnTargetKilled(AActor* Target)
{
	UDamageReceiver* DamageReceiver = Target->FindComponentByClass<UDamageReceiver>();
	Targets.Remove(DamageReceiver);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Target Slain. Targets remaining: %i"), Targets.Num()));

	if (Targets.Num() <= 0)
	{
		EndMission(EMissionEndType::MissionEndType_Success);
	}
}
