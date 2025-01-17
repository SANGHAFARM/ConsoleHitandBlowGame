#include "PlayerCursor.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

PlayerCursor::PlayerCursor(GameLevel* level)
	: Super(""), refLevel(level)
{
	// ��ġ ����
	this->position = Vector2((Engine::Get().ScreenSize().x * 2) / 3 + 11, 11);

	// ����� ���� �Ŀ� ��ġ�� �ʱ�ȭ�ϱ� ���� �⺻ ��ġ ����
	defaultPostion = this->position;

	selectedButton = Vector2(position.x, position.y - 1);
	refLevel->CheckButtonAndSelect(selectedButton);
}

void PlayerCursor::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		// �޴� ���
		Game::Get().ToggleMenu();
	}

	// �������� Ŀ�� �̵�
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		Vector2 newPosition = Vector2(selectedButton.x - 6, selectedButton.y);

		if (refLevel->CheckButtonAndSelect(newPosition))
		{
			this->position = Vector2(position.x - 6, position.y);
			selectedButton = newPosition;
		}
	}

	// ���������� Ŀ�� �̵�
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		Vector2 newPosition = Vector2(selectedButton.x + 6, selectedButton.y);

		if (refLevel->CheckButtonAndSelect(newPosition))
		{
			this->position = Vector2(position.x + 6, position.y);
			selectedButton = newPosition;
		}
	}

	// ���� Ŀ�� �̵�
	if (Engine::Get().GetKeyDown(VK_UP))
	{
		Vector2 newPosition = Vector2(selectedButton.x, selectedButton.y - 3);

		if (refLevel->CheckButtonAndSelect(newPosition))
		{
			this->position = Vector2(position.x, position.y - 3);
			selectedButton = newPosition;
		}
	}

	// �Ʒ��� Ŀ�� �̵�
	if (Engine::Get().GetKeyDown(VK_DOWN))
	{
		Vector2 newPosition = Vector2(selectedButton.x, selectedButton.y + 3);

		if (refLevel->CheckButtonAndSelect(newPosition))
		{
			this->position = Vector2(position.x, position.y + 3);
			selectedButton = newPosition;
		}
	}
}