#include "./R-Type/Entities/Bullet.h"
#include "./Core/Sprite.h"


Bullet::Bullet(const char* texturePath)
	: Entity(texturePath)
{
}

Bullet::Bullet(const char* texturePath, const int columns, const int rows)
	: Entity(texturePath, columns, rows)
{
}

void Bullet::Update(float deltaTime)
{
	SetPosX(GetPosX() + m_MoveSpeed * deltaTime);
}
