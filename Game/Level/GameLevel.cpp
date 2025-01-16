#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Engine/Timer.h"
#include "Math/Vector2.h"
#include "Actor/Button.h"

#include <time.h>

GameLevel::GameLevel()
{	
	InitializePad();

	// ���� �迭�� �ߺ����� �ʴ� ���� ���� ä���
	while (answer.Size() < 4)
	{
		int index = Random(1, 9);

		bool alreadyExist = false;
		for (int i = 0; i < answer.Size(); i++)
		{
			if (index == answer[i])
			{
				alreadyExist = true;
				break;
			}
		}

		if (alreadyExist == false)
		{
			answer.PushBack(index);
		}
	}

	AddActor(new Button("<1>", Vector2(numberPadStartX + 2, numberPadStartY + 6)));
	AddActor(new Button("<2>", Vector2(numberPadStartX + 8, numberPadStartY + 6)));
	AddActor(new Button("<3>", Vector2(numberPadStartX + 14, numberPadStartY + 6)));
	AddActor(new Button("<4>", Vector2(numberPadStartX + 2, numberPadStartY + 9)));
	AddActor(new Button("<5>", Vector2(numberPadStartX + 8, numberPadStartY + 9)));
	AddActor(new Button("<6>", Vector2(numberPadStartX + 14, numberPadStartY + 9)));
	AddActor(new Button("<7>", Vector2(numberPadStartX + 2, numberPadStartY + 12)));
	AddActor(new Button("<8>", Vector2(numberPadStartX + 8, numberPadStartY + 12)));
	AddActor(new Button("<9>", Vector2(numberPadStartX + 14, numberPadStartY + 12)));

	AddActor(new Button("O K", Vector2(numberPadStartX + 8, numberPadStartY + 15)));
	AddActor(new Button("��--", Vector2(numberPadStartX + 14, numberPadStartY + 3)));
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ������ Ŭ���������, ���� ���� ó��
	if (isGameClear)
	{
		// Ÿ�̸�
		static Timer timer(0.1f);
		timer.Update(deltaTime);
		if (!timer.IsTimeOut())
		{
			return;
		}

		// Ŀ�� �̵�
		Engine::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y);

		// �޽��� ���
		Log("Game Clear!");

		// ������ ����
		Sleep(2000);

		// ���� ���� ó��
		Engine::Get().QuitGame();
	}
}

void GameLevel::Draw()
{
	Super::Draw();

}

void GameLevel::InitializePad()
{
	int screenSizeX = Engine::Get().ScreenSize().x;
	int screenSizeY = Engine::Get().ScreenSize().y;

	Engine::Get().SetCursorPosition(0, 0);
	Log("��");
	Engine::Get().SetCursorPosition(screenSizeX, 0);
	Log("��");
	Engine::Get().SetCursorPosition(0, screenSizeY);
	Log("��");
	Engine::Get().SetCursorPosition(screenSizeX, screenSizeY);
	Log("��");

	for (int i = 1; i < screenSizeX; i++)
	{
		Engine::Get().SetCursorPosition(i, 0);
		Log("��");
		Engine::Get().SetCursorPosition(i, screenSizeY);
		Log("��");
	}
	
	for (int i = 1; i < screenSizeY; i++)
	{
		Engine::Get().SetCursorPosition(0, i);
		Log("��");
		Engine::Get().SetCursorPosition(screenSizeX, i);
		Log("��");
	}

	Engine::Get().SetCursorPosition(numberPadStartX, numberPadStartY);
	Log("��");
	Engine::Get().SetCursorPosition(screenSizeX - 1, numberPadStartY);
	Log("��");
	Engine::Get().SetCursorPosition(numberPadStartX, screenSizeY - 1);
	Log("��");
	Engine::Get().SetCursorPosition(screenSizeX - 1, screenSizeY - 1);
	Log("��");
	for (int i = numberPadStartX + 1; i < screenSizeX - 1; i++)
	{
		Engine::Get().SetCursorPosition(i, numberPadStartY);
		Log("��");
		Engine::Get().SetCursorPosition(i, screenSizeY - 1);
		Log("��");
	}
}

bool GameLevel::CheckGameClear()
{
	return false;
}
