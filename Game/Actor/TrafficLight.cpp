#include "TrafficLight.h"

TrafficLight::TrafficLight(Vector2 position)
	: Super("��")
{
	// ���� ����
	this->color = Color::Red;

	// �̸� ����
	this->position = position;
}
