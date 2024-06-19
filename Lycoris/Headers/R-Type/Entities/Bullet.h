#pragma once

#include "./Projectile.h"

class Bullet : public Projectile
{
public:
	Bullet(const char* texturePath);
	Bullet(const char* texturePath, const int columns, const int rows);

	~Bullet() override;

	void Update(float deltaTime) override;
};
