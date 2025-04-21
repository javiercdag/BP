// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct BPIXEL_API EventData{};

template<typename T>
class BPIXEL_API EventBuffer
{
	static_assert(std::is_base_of<EventData, T>::value, "T must inherit from EventData");
public:
	virtual ~EventBuffer() = default;
	
	virtual void AddEvent(T event)
	{
		Events.Add(event);
	}
	
protected:
	TArray<T> Events;

	virtual void Process() = 0;
};
