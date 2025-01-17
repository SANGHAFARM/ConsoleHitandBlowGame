#include "Button.h"
#include "Math/Vector2.h"
#include "Engine/Engine.h"

Button::Button(const char* image, Vector2 position, const char* buttonName)
	: Super(image)
{
	// ��ư Ȯ���� ���� ��ư�� �̸��� ����
	auto length = strlen(buttonName) + 1;
	this->buttonName = new char[length];
	strcpy_s(this->buttonName, length, buttonName);

	// ��ġ ����
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
