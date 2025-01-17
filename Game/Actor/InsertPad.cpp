#include "InsertPad.h"

InsertPad::InsertPad(const char* image, Vector2 position)
	: Super(image)
{
	// ��ġ ����
	this->position = position;
}

void InsertPad::SetImage(const char* newImage)
{
	if (this->image != nullptr)
	{
		delete[] this->image;
	}

	// ���� ���� ���ڿ� ����
	auto length = strlen(newImage) + 1;
	this->image = new char[length];
	strcpy_s(this->image, length, newImage);

	// �ʺ� ����
	width = (int)strlen(newImage);
}
