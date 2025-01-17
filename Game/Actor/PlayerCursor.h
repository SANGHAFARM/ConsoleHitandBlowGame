#pragma once

#include "Actor/DrawableActor.h"

class GameLevel;

class PlayerCursor : public DrawableActor
{
	RTTI_DECLARATIONS(PlayerCursor, DrawableActor)

public:
	PlayerCursor(GameLevel* level);

	virtual void Update(float deltaTime) override;

private:
	// 초기 위치 저장 변수
	Vector2 defaultPostion;

	// 플레이어 커서가 현재 선택 중인 버튼 위치
	Vector2 selectedButton;

	// 게임 레벨 참조 변수
	GameLevel* refLevel = nullptr;
};