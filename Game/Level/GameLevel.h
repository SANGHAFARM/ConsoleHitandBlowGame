#pragma once

#include "Level/Level.h"
#include "Engine/Engine.h"

class Button;
class PlayerCursor;
class InsertPad;

class GameLevel : public Level
{
    RTTI_DECLARATIONS(GameLevel, Level)

public:
    GameLevel();

    // ������Ʈ �Լ�
    virtual void Update(float deltaTime) override;

    // ������ �׸��� �Լ�
    virtual void Draw() override;

    // ���������� �׸��� �Լ�
    void InitializePad();

    // �������� �⺻ ���͸� �߰��ϴ� �Լ�
    void InitializeActors();

    // �ش� ��ġ�� ��ư���� Ȯ���ϰ� ���� ǥ�� Ȱ��ȭ
    bool CheckButtonAndSelect(const Vector2& position);
        
private:
    // ������ Ŭ�����ߴ��� Ȯ���ϴ� �Լ�
    bool CheckGameClear();

private:
    // ���� Ŭ���� ����
    bool isGameClear = false;

    // ��ư ���� �迭
    List<Button*> buttons;

    // ���� ���� ���� �迭
    List<InsertPad*> insertPads;

    // ���� �迭
    List<int> answer;

    // �Է� �迭
    List<int> input;

    // �÷��̾� Ŀ��
    PlayerCursor* playerCursor = nullptr;

    // ������ �����ߴ� ��ư
    Button* previousButton = nullptr;
};