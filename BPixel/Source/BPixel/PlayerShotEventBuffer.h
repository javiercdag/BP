#pragma once

#include "EventBuffer.h"

struct BPIXEL_API PlayerShotEventData : EventData
{
	
};

class PlayerShotEventBuffer : public EventBuffer<PlayerShotEventData>
{
public:
	virtual void Process() override;
};
