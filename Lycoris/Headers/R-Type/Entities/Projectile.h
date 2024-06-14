#pragma once
#include "Entities/Entity.h"

class Projectile : public Entity
{
public:
	Projectile(const char* texturePath);
	Projectile(const char* texturePath, const int columns, const int rows);

	float GetMoveSpeed() const;
	void SetMoveSpeed(float newSpeed);

private:
	float m_MoveSpeed = 1000.f;
	
};
