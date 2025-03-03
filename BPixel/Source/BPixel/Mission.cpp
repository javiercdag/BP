// Fill out your copyright notice in the Description page of Project Settings.


#include "Mission.h"

UMission::UMission()
{
}

void UMission::StartMission()
{
	RunActions(PreMissionStartActions);
	OnMissionStart();
	RunActions(PostMissionStartActions);
}

void UMission::EndMission(const EMissionEndType Reason)
{
	RunActions(PreMissionEndActions);
	OnMissionEnd();
	OnMissionEnded.Broadcast(this, Reason);
	RunActions(PostMissionEndActions);
}

void UMission::OnMissionStart() { }
void UMission::OnMissionEnd() { }

void UMission::RunActions(TArray<TSubclassOf<UMissionAction>> Actions)
{
	for (int i = 0; i < Actions.Num(); i++)
	{
		if (UMissionAction* MissionActionInstance = NewObject<UMissionAction>(this, Actions[i]))
		{
			MissionActionInstance->DoAction();
		}
	}
}
