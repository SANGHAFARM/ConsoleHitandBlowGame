#pragma once

#include "Actor.h"

class ENGINE_API DrawableActor : public Actor
{
	// RTTI
	RTTI_DECLARATIONS(DrawableActor, Actor)

public:
	DrawableActor(const char* image = " ");
	virtual ~DrawableActor();

	virtual void Draw() override;	
	virtual void SetPosition(const Vector2& newPosition) override;

	// 액터의 테두리를 그리는 함수
	void DrawOutline();

	// 액터의 색상을 설정하는 함수
	void SetActorColor(Color color);

	// 충돌 확인 함수
	bool Intersect(const DrawableActor& other);

	// Getter
	inline int Width() const { return width; }

protected:
	// 화면에 그릴 문자 값
	char* image;

	// 너비 (문자열 길이)
	int width = 0;

	// 색상 값 (Material)
	Color color = Color::White;
};