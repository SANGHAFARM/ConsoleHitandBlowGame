#include "Button.h"
#include "Math/Vector2.h"
#include "Engine/Engine.h"

Button::Button(const char* image, Vector2 position, const char* buttonName)
	: Super(image)
{
	// 버튼 확인을 위해 버튼의 이름을 설정
	auto length = strlen(buttonName) + 1;
	this->buttonName = new char[length];
	strcpy_s(this->buttonName, length, buttonName);

	// 위치 설정
	this->position = position;		
}

Button::~Button()
{
	delete[] buttonName;
}

void Button::Update(float deltaTime)
{
	Super::Update(deltaTime);
}
