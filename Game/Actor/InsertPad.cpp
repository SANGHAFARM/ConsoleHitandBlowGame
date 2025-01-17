#include "InsertPad.h"

InsertPad::InsertPad(const char* image, Vector2 position)
	: Super(image)
{
	// 위치 설정
	this->position = position;
}

void InsertPad::SetImage(const char* newImage)
{
	if (this->image != nullptr)
	{
		delete[] this->image;
	}

	// 전달 받은 문자열 복사
	auto length = strlen(newImage) + 1;
	this->image = new char[length];
	strcpy_s(this->image, length, newImage);

	// 너비 설정
	width = (int)strlen(newImage);
}
