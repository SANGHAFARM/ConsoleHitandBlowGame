#include "Game/Game.h"
#include "Level/GameLevel.h"

#include <iostream>

int main()
{
	// 메모리 누수 확인
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new GameLevel());
	game.Run();
}