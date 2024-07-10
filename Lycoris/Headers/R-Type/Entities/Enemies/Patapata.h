#pragma once
#include "./Entities/Entity.h"

class Patapata : public Entity
{
public:
	Patapata(const char* texturePath, const int columns, const int rows);

	void Update(float deltaTime) override;
};
