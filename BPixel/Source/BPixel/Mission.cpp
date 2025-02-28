// Fill out your copyright notice in the Description page of Project Settings.


#include "Mission.h"

UMission::UMission()
{
}

void UMission::StartMission()
{
}

void UMission::EndMission(const EMissionEndType Reason)
{
	OnMissionEnded.Broadcast(this, Reason);
}