#pragma once

#include "Actor/DrawableActor.h"

class InsertPad : public DrawableActor
{
	RTTI_DECLARATIONS(InsertPad, DrawableActor)

public:
	InsertPad(const char* image, Vector2 position);

	void SetImage(const char* newImage);
};