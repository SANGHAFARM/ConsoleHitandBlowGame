#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"

#include <iostream>

Level::Level()
{
}

Level::~Level()
{
	// �޸� ����
	for (Actor* actor : actors)
	{
		delete actor;
	}
}

void Level::AddActor(Actor* newActor)
{
	actors.PushBack(newActor);
	//addRequestedActor = newActor;
}

void Level::ProcessAddedAndDestroyedActor()
{
	// ���� ��ȸ �� ���� ��û�� ���͸� ó��
	for (int i = 0; i < actors.Size();)
	{
		if (actors[i]->isExpired)
		{
			delete actors[i];
			actors[i] = nullptr;
			actors.Erase(i);
			continue;
		}

		i++;
	}

	// �߰� ��û�� ���� ó��
	//if (addRequestedActor)
	//{
	//	actors.PushBack(addRequestedActor);
	//	addRequestedActor = nullptr;
	//}
}

void Level::Update(float deltaTime)
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Update �Լ� ȣ��
	for (Actor* actor : actors)
	{
		// ���Ͱ� ��Ȱ�� �����̰ų�, ���� ��û�� ��� �ǳʶٱ�
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}

		actor->Update(deltaTime);
	}
}

void Level::Draw()
{
	// ������ ���Ե� ���͸� ��ȸ�ϸ鼭 Draw �Լ� ȣ��
	for (Actor* actor : actors)
	{
		// ���Ͱ� ��Ȱ�� �����̰ų�, ���� ��û�� ��� �ǳʶٱ�
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}

		actor->Draw();
	}
}
