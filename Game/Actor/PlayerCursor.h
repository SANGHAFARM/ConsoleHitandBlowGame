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
	// �ʱ� ��ġ ���� ����
	Vector2 defaultPostion;

	// �÷��̾� Ŀ���� ���� ���� ���� ��ư ��ġ
	Vector2 selectedButton;

	// ���� ���� ���� ����
	GameLevel* refLevel = nullptr;
};