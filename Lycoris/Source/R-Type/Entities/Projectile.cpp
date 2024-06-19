#include "./R-Type/Entities/Projectile.h"

#include <iostream>

#include "./Core/Sprite.h"

Projectile::Projectile(const char* texturePath)
	:Entity(texturePath)
{
}

Projectile::Projectile(const char* texturePath, const int columns, const int rows)
	:Entity(texturePath, columns,rows)
{
}

Projectile::~Projectile()
{
	std::cout << "Deleted Projectile!\n";
}

float Projectile::GetMoveSpeed() const
{
	return m_MoveSpeed;
}

void Projectile::SetMoveSpeed(float newSpeed)
{
	m_MoveSpeed = newSpeed;
}

bool Projectile::ShouldRemove() const
{
	return m_CanRemove;
}
