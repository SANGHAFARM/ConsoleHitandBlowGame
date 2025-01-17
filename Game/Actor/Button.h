#pragma once

#include "Actor/DrawableActor.h"

class Vector2;

class Button : public DrawableActor
{
	RTTI_DECLARATIONS(Button, DrawableActor)

public:
	Button(const char* image, Vector2 position, const char* buttonName);
	~Button();
	
	virtual void Update(float deltaTime) override;

	inline char* GetButtonName() const { return buttonName; }

private:
	char* buttonName;
};