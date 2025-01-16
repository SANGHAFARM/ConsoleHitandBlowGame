#include "Button.h"
#include "Math/Vector2.h"

Button::Button(const char* image, Vector2 position)
	: Super(image)
{
	this->position = position;
}

void Button::Update(float deltaTime)
{
	Super::Update(deltaTime);
}
