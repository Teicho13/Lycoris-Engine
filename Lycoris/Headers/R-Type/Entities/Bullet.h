#pragma once
#include "./Entities/Entity.h"

class Bullet : public Entity
{
public:
	Bullet(const char* texturePath);
	Bullet(const char* texturePath, const int columns, const int rows);

	void Update(float deltaTime) override;

private:
	float m_MoveSpeed = 1000.f;
};
