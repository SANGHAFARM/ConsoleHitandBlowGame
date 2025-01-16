#pragma once

#include "Level/Level.h"
#include "Engine/Engine.h"

class Button;

class GameLevel : public Level
{
    RTTI_DECLARATIONS(GameLevel, Level)

public:
    GameLevel();

    // 업데이트 함수
    virtual void Update(float deltaTime) override;

    // 레벨을 그리는 함수
    virtual void Draw() override;

    // 스테이지와 숫자패드를 그리는 함수
    void InitializePad();
        
private:
    // 게임을 클리어했는지 확인하는 함수
    bool CheckGameClear();

private:
    // 게임 클리어 변수
    bool isGameClear = false;

    // 버튼 액터 배열
    List<Button*> buttons;

    // 정답 배열
    List<int> answer;

    // 입력 배열
    List<int> input;

    // 숫자 패드 시작점의 x좌표와 y좌표
    int numberPadStartX = (Engine::Get().ScreenSize().x * 2) / 3 + 1;
    int numberPadStartY = 1;
};