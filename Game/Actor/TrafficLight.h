#pragma once

#include "Actor/DrawableActor.h"

class TrafficLight : public DrawableActor
{
	RTTI_DECLARATIONS(TrafficLight, DrawableActor)

public:
	TrafficLight(Vector2 position);

};