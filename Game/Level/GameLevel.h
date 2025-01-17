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

    // 업데이트 함수
    virtual void Update(float deltaTime) override;

    // 레벨을 그리는 함수
    virtual void Draw() override;

    // 스테이지를 그리는 함수
    void InitializePad();

    // 스테이지 기본 액터를 추가하는 함수
    void InitializeActors();

    // 해당 위치가 버튼인지 확인하고 선택 표시 활성화
    bool CheckButtonAndSelect(const Vector2& position);
        
private:
    // 게임을 클리어했는지 확인하는 함수
    bool CheckGameClear();

private:
    // 게임 클리어 변수
    bool isGameClear = false;

    // 버튼 액터 배열
    List<Button*> buttons;

    // 정답 삽입 액터 배열
    List<InsertPad*> insertPads;

    // 정답 배열
    List<int> answer;

    // 입력 배열
    List<int> input;

    // 플레이어 커서
    PlayerCursor* playerCursor = nullptr;

    // 이전에 선택했던 버튼
    Button* previousButton = nullptr;
};