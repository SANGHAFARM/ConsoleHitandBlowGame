#include "Game/Game.h"
#include "Level/GameLevel.h"

#include <iostream>

int main()
{
	// �޸� ���� Ȯ��
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new GameLevel());
	game.Run();
}