#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Engine/Timer.h"
#include "Math/Vector2.h"
#include "Actor/Button.h"
#include "Actor/InsertPad.h"
#include "Actor/TrafficLight.h"
#include "Actor/PlayerCursor.h"

#include <time.h>

GameLevel::GameLevel()
{	
	InitializeActors();
	InitializePad();

	// 정답 배열에 중복되지 않는 랜덤 숫자 채우기
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

	for (auto* actor : actors)
	{		
		if (actor->As<Button>())
		{
			buttons.PushBack(actor->As<Button>());
		}

		if (actor->As<InsertPad>())
		{
			insertPads.PushBack(actor->As<InsertPad>());
		}
	}

	// 플레이어 커서 액터 추가
	playerCursor = new PlayerCursor(this);
	actors.PushBack(playerCursor);

	Engine::Get().SetCursorType(CursorType::NoCursor);
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// 게임이 클리어됐으면, 게임 종료 처리
	if (isGameClear)
	{
		// 타이머
		static Timer timer(0.1f);
		timer.Update(deltaTime);
		if (!timer.IsTimeOut())
		{
			return;
		}

		// 커서 이동
		Engine::Get().SetCursorPosition(0, Engine::Get().ScreenSize().y);

		// 메시지 출력
		Log("Game Clear!");

		// 쓰레드 정지
		Sleep(2000);

		// 게임 종료 처리
		Engine::Get().QuitGame();
	}
}

void GameLevel::Draw()
{
	Super::Draw();

	InitializePad();
}

void GameLevel::InitializePad()
{
	// 화면 끝의 x좌표/y좌표
	int screenSizeX = Engine::Get().ScreenSize().x;
	int screenSizeY = Engine::Get().ScreenSize().y;

	// 숫자 패드 시작점의 x좌표와 y좌표
	int numberPadStartX = (Engine::Get().ScreenSize().x * 2) / 3 + 2;
	int numberPadStartY = 1;

	// 전체 화면 패드 테두리
	Engine::Get().SetCursorPosition(0, 0);
	Log("┌");
	Engine::Get().SetCursorPosition(screenSizeX, 0);
	Log("┐");
	Engine::Get().SetCursorPosition(0, screenSizeY);
	Log("└");
	Engine::Get().SetCursorPosition(screenSizeX, screenSizeY);
	Log("┘");

	for (int i = 1; i < screenSizeX; i++)
	{
		Engine::Get().SetCursorPosition(i, 0);
		Log("─");
		Engine::Get().SetCursorPosition(i, screenSizeY);
		Log("─");
	}

	// 내부 좌측 Try 패드 테두리
	Engine::Get().SetCursorPosition(1, 1);
	Log("┌");
	Engine::Get().SetCursorPosition(numberPadStartX - 1, 1);
	Log("┐");
	Engine::Get().SetCursorPosition(1, screenSizeY - 1);
	Log("└");
	Engine::Get().SetCursorPosition(numberPadStartX - 1, screenSizeY - 1);
	Log("┘");
	
	for (int i = 1; i < screenSizeY; i++)
	{
		Engine::Get().SetCursorPosition(0, i);
		Log("│");
		Engine::Get().SetCursorPosition(screenSizeX, i);
		Log("│");
	}

	// 내부 우측 숫자 패드 테두리
	Engine::Get().SetCursorPosition(numberPadStartX, numberPadStartY);
	Log("┌");
	Engine::Get().SetCursorPosition(screenSizeX - 1, numberPadStartY);
	Log("┐");
	Engine::Get().SetCursorPosition(numberPadStartX, screenSizeY - 1);
	Log("└");
	Engine::Get().SetCursorPosition(screenSizeX - 1, screenSizeY - 1);
	Log("┘");
	for (int i = numberPadStartX + 1; i < screenSizeX - 1; i++)
	{
		Engine::Get().SetCursorPosition(i, numberPadStartY);
		Log("─");
		Engine::Get().SetCursorPosition(i, screenSizeY - 1);
		Log("─");
	}

	// 신호등 표시기 테두리
	int trafficLightPadStartX = numberPadStartX - 16;
	int trafficLightPadStartY = numberPadStartY + 1;

	for (int i = trafficLightPadStartY; i < screenSizeY - 2; i += 3)
	{
		Engine::Get().SetCursorPosition(trafficLightPadStartX, i);
		Log("┌");
		Engine::Get().SetCursorPosition(trafficLightPadStartX, i + 2);
		Log("└");


		Engine::Get().SetCursorPosition(trafficLightPadStartX + 13, i);
		Log("┐");
		Engine::Get().SetCursorPosition(trafficLightPadStartX + 13, i + 2);
		Log("┘");
	}
	
	for (int i = trafficLightPadStartX + 1; i < numberPadStartX - 3; i++)
	{
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 2);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 3);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 5);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 6);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 8);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 9);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 11);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 12);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 14);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 15);
		Log("─");
		Engine::Get().SetCursorPosition(i, trafficLightPadStartY + 17);
		Log("─");
	}

	for (auto* button : buttons)
	{
		button->DrawOutline();
	}

	for (auto* insertPad : insertPads)
	{
		insertPad->DrawOutline();
	}
}

void GameLevel::InitializeActors()
{
	// 숫자 패드 시작점의 x좌표와 y좌표
	int numberPadStartX = (Engine::Get().ScreenSize().x * 2) / 3 + 2;
	int numberPadStartY = 1;

	// 정답 입력 패드 액터 추가
	AddActor(new InsertPad("0", Vector2(5, 3)));
	AddActor(new InsertPad("0", Vector2(11, 3)));
	AddActor(new InsertPad("0", Vector2(17, 3)));
	AddActor(new InsertPad("0", Vector2(23, 3)));

	AddActor(new InsertPad("#", Vector2(5, 6)));
	AddActor(new InsertPad("#", Vector2(11, 6)));
	AddActor(new InsertPad("#", Vector2(17, 6)));
	AddActor(new InsertPad("#", Vector2(23, 6)));

	AddActor(new InsertPad("#", Vector2(5, 9)));
	AddActor(new InsertPad("#", Vector2(11, 9)));
	AddActor(new InsertPad("#", Vector2(17, 9)));
	AddActor(new InsertPad("#", Vector2(23, 9)));

	AddActor(new InsertPad("#", Vector2(5, 12)));
	AddActor(new InsertPad("#", Vector2(11, 12)));
	AddActor(new InsertPad("#", Vector2(17, 12)));
	AddActor(new InsertPad("#", Vector2(23, 12)));

	AddActor(new InsertPad("#", Vector2(5, 15)));
	AddActor(new InsertPad("#", Vector2(11, 15)));
	AddActor(new InsertPad("#", Vector2(17, 15)));
	AddActor(new InsertPad("#", Vector2(23, 15)));

	AddActor(new InsertPad("#", Vector2(5, 18)));
	AddActor(new InsertPad("#", Vector2(11, 18)));
	AddActor(new InsertPad("#", Vector2(17, 18)));
	AddActor(new InsertPad("#", Vector2(23, 18)));

	// 신호등 표시기 액터 추가
	AddActor(new TrafficLight(Vector2(29, 3)));
	AddActor(new TrafficLight(Vector2(32, 3)));
	AddActor(new TrafficLight(Vector2(35, 3)));
	AddActor(new TrafficLight(Vector2(38, 3)));

	// 숫자패드 버튼 액터 추가
	AddActor(new Button(" 1 ", Vector2(numberPadStartX + 2, numberPadStartY + 6), "1"));
	AddActor(new Button(" 2 ", Vector2(numberPadStartX + 8, numberPadStartY + 6), "2"));
	AddActor(new Button(" 3 ", Vector2(numberPadStartX + 14, numberPadStartY + 6), "3"));
	AddActor(new Button(" 4 ", Vector2(numberPadStartX + 2, numberPadStartY + 9), "4"));
	AddActor(new Button(" 5 ", Vector2(numberPadStartX + 8, numberPadStartY + 9), "5"));
	AddActor(new Button(" 6 ", Vector2(numberPadStartX + 14, numberPadStartY + 9), "6"));
	AddActor(new Button(" 7 ", Vector2(numberPadStartX + 2, numberPadStartY + 12), "7"));
	AddActor(new Button(" 8 ", Vector2(numberPadStartX + 8, numberPadStartY + 12), "8"));
	AddActor(new Button(" 9 ", Vector2(numberPadStartX + 14, numberPadStartY + 12), "9"));

	AddActor(new Button("   O K   ", Vector2(numberPadStartX + 8, numberPadStartY + 15), "ok"));
	AddActor(new Button("     ←--", Vector2(numberPadStartX + 8, numberPadStartY + 3), "back"));
}

bool GameLevel::CheckButtonAndSelect(const Vector2& position)
{
	for (auto* button : buttons)
	{
		int min = button->GetPosition().x;
		int max = button->GetPosition().x + button->Width();
		int buttonY = button->GetPosition().y;

		// y위치 비교
		if (position.y == buttonY)
		{
			// y위치가 같으면, x위치가 button 액터 width 내부에 있는지 비교
			if (position.x > min && position.x < max)
			{
				if (previousButton)
				{
					previousButton->SetActorColor(Color::White);
				}

				button->SetActorColor(Color::Blue);
				previousButton = button;

				return true;
			}
		}
	}

	return false;
}

bool GameLevel::CheckGameClear()
{
	return false;
}
