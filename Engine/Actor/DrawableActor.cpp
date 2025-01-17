#include "PreCompiledHeader.h"
#include "DrawableActor.h"
#include "Engine/Engine.h"

DrawableActor::DrawableActor(const char* image)
	: Actor()
{
	// ���� ���� ���ڿ� ����
	auto length = strlen(image) + 1;
	this->image = new char[length];
	strcpy_s(this->image, length, image);

	// �ʺ� ����
	width = (int)strlen(image);
}

DrawableActor::~DrawableActor()
{
	delete[] image;
}

void DrawableActor::Draw()
{
	Super::Draw();

	// ���� ����
	SetColor(color);

	// �׸���
	// 1�ܰ� : �ܼ� ��ǥ �ű��
	Engine::Get().SetCursorPosition(position);

	// 2�ܰ� : �׸��� (�ܼ� ���)
	Log(image);

	// ���� ����
	SetColor(Color::White);
}

void DrawableActor::SetPosition(const Vector2& newPosition)
{
	//// ������ ��ġ�� ���� �����
	//Engine::Get().SetCursorPosition(position);
	//Log(" ");

	// ��ġ�� ���� �ű��
	Super::SetPosition(newPosition);
}

void DrawableActor::DrawOutline()
{
	// �ּ��� ���簢���� ����� ���� width�� 3���� ���� ��� 
	// ���� ���� ��ġ ���ؿ��� x - 2���� x + 2 ��ǥ���� �׸����� ����
	if (width < 3)
	{
		Engine::Get().SetCursorPosition(position.x - 2, position.y - 1);
		Log("��");
		Engine::Get().SetCursorPosition(position.x + 2, position.y - 1);
		Log("��");
		Engine::Get().SetCursorPosition(position.x - 2, position.y + 1);
		Log("��");
		Engine::Get().SetCursorPosition(position.x + 2, position.y + 1);
		Log("��");

		Engine::Get().SetCursorPosition(position.x + 2, position.y);
		Log("��");
		Engine::Get().SetCursorPosition(position.x - 2, position.y);
		Log("��");

		for (int i = 0; i < 3; i++)
		{
			Engine::Get().SetCursorPosition(position.x + i - 1, position.y + 1);
			Log("��");
			Engine::Get().SetCursorPosition(position.x + i - 1, position.y - 1);
			Log("��");
		}
	}
	else
	{
		Engine::Get().SetCursorPosition(position.x - 1, position.y - 1);
		Log("��");
		Engine::Get().SetCursorPosition(position.x + width, position.y - 1);
		Log("��");
		Engine::Get().SetCursorPosition(position.x - 1, position.y + 1);
		Log("��");
		Engine::Get().SetCursorPosition(position.x + width, position.y + 1);
		Log("��");

		Engine::Get().SetCursorPosition(position.x + width, position.y);
		Log("��");
		Engine::Get().SetCursorPosition(position.x - 1, position.y);
		Log("��");

		for (int i = 0; i < width; i++)
		{
			Engine::Get().SetCursorPosition(position.x + i, position.y + 1);
			Log("��");
			Engine::Get().SetCursorPosition(position.x + i, position.y - 1);
			Log("��");
		}
	}
}

void DrawableActor::SetActorColor(Color color)
{
	this->color = color;
}

bool DrawableActor::Intersect(const DrawableActor& other)
{
	// AABB (Axis Aligned Bounding Box)

	// �� x��ǥ �ּ�/�ִ�
	int min = position.x;
	int max = position.x + width;

	// �ٸ� ������ x��ǥ �ּ�/�ִ�
	int otherMin = other.position.x;
	int otherMax = other.position.x + other.width;

	// �ٸ� ������ ���� �� ��ġ�� �� ������ �� ��ġ�� ����� �浹 �� ��
	if (otherMin > max)
	{
		return false;
	}

	// �ٸ� ������ ������ �� ��ġ�� �� ���� �� ��ġ���� ������ �浹 �� ��
	if (otherMax < min)
	{
		return false;
	}

	// ���� �� ��찡 �ƴ϶�� (x��ǥ�� ���� ��ħ), y��ġ ��
	return position.y == other.position.y;
}
