// Fill out your copyright notice in the Description page of Project Settings.


#include "Mission.h"

UMission::UMission()
{
}

void UMission::Initialize(UMissionDataAsset* MissionData)
{
	for (int i = 0; i < MissionData->PreMissionStartActions.Num(); i++)
	{
		PreMissionStartActions.Add(NewObject<UMissionAction>(this, MissionData->PreMissionStartActions[i]->MissionActionClass));
		PreMissionStartActions[i]->Initialize(MissionData->PreMissionStartActions[i]);
	}

	for (int i = 0; i < MissionData->PostMissionStartActions.Num(); i++)
	{
		PostMissionStartActions.Add(NewObject<UMissionAction>(this, MissionData->PostMissionStartActions[i]->MissionActionClass));
		PostMissionStartActions[i]->Initialize(MissionData->PostMissionStartActions[i]);
	}

	for (int i = 0; i < MissionData->PreMissionEndActions.Num(); i++)
	{
		PreMissionEndActions.Add(NewObject<UMissionAction>(this, MissionData->PreMissionEndActions[i]->MissionActionClass));
		PreMissionEndActions[i]->Initialize(MissionData->PreMissionEndActions[i]);
	}
	
	for (int i = 0; i < MissionData->PostMissionEndActions.Num(); i++)
	{
		PostMissionEndActions.Add(NewObject<UMissionAction>(this, MissionData->PostMissionEndActions[i]->MissionActionClass));
		PostMissionEndActions[i]->Initialize(MissionData->PostMissionEndActions[i]);
	}
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

void UMission::RunActions(TArray<UMissionAction*> Actions)
{
	for (int i = 0; i < Actions.Num(); i++)
	{
		Actions[i]->DoAction();
	}
}
