#include "TrafficLight.h"

TrafficLight::TrafficLight(Vector2 position)
	: Super("●")
{
	// 색상 설정
	this->color = Color::Red;

	// 이름 설정
	this->position = position;
}
