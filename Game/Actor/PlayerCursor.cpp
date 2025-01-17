#include "PlayerCursor.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

PlayerCursor::PlayerCursor(GameLevel* level)
	: Super(""), refLevel(level)
{
	// 위치 설정
	this->position = Vector2((Engine::Get().ScreenSize().x * 2) / 3 + 11, 11);

	// 페이즈가 끝난 후에 위치를 초기화하기 위한 기본 위치 설정
	defaultPostion = this->position;

	selectedButton = Vector2(position.x, position.y - 1);
	refLevel->CheckButtonAndSelect(selectedButton);
}

void PlayerCursor::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		// 메뉴 토글
		Game::Get().ToggleMenu();
	}

	// 왼쪽으로 커서 이동
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		Vector2 newPosition = Vector2(selectedButton.x - 6, selectedButton.y);

		if (refLevel->CheckButtonAndSelect(newPosition))
		{
			this->position = Vector2(position.x - 6, position.y);
			selectedButton = newPosition;
		}
	}

	// 오른쪽으로 커서 이동
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		Vector2 newPosition = Vector2(selectedButton.x + 6, selectedButton.y);

		if (refLevel->CheckButtonAndSelect(newPosition))
		{
			this->position = Vector2(position.x + 6, position.y);
			selectedButton = newPosition;
		}
	}

	// 위로 커서 이동
	if (Engine::Get().GetKeyDown(VK_UP))
	{
		Vector2 newPosition = Vector2(selectedButton.x, selectedButton.y - 3);

		if (refLevel->CheckButtonAndSelect(newPosition))
		{
			this->position = Vector2(position.x, position.y - 3);
			selectedButton = newPosition;
		}
	}

	// 아래로 커서 이동
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