#pragma once

#include "Level/Level.h"
#include "Engine/Engine.h"

class Button;

class GameLevel : public Level
{
    RTTI_DECLARATIONS(GameLevel, Level)

public:
    GameLevel();

    // ������Ʈ �Լ�
    virtual void Update(float deltaTime) override;

    // ������ �׸��� �Լ�
    virtual void Draw() override;

    // ���������� �����е带 �׸��� �Լ�
    void InitializePad();
        
private:
    // ������ Ŭ�����ߴ��� Ȯ���ϴ� �Լ�
    bool CheckGameClear();

private:
    // ���� Ŭ���� ����
    bool isGameClear = false;

    // ��ư ���� �迭
    List<Button*> buttons;

    // ���� �迭
    List<int> answer;

    // �Է� �迭
    List<int> input;

    // ���� �е� �������� x��ǥ�� y��ǥ
    int numberPadStartX = (Engine::Get().ScreenSize().x * 2) / 3 + 1;
    int numberPadStartY = 1;
};