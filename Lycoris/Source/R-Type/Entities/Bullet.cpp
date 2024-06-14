#include "./R-Type/Entities/Bullet.h"
#include "./Core/Sprite.h"


Bullet::Bullet(const char* texturePath)
	: Projectile(texturePath)
{
}

Bullet::Bullet(const char* texturePath, const int columns, const int rows)
	: Projectile(texturePath, columns, rows)
{
}

void Bullet::Update(float deltaTime)
{
	SetPosX(GetPosX() + GetMoveSpeed() * deltaTime);
}
