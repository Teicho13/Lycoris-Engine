#include "./R-Type/Entities/Bullet.h"

#include <iostream>

#include "./Core/Sprite.h"
#include "./Core/Utility/AppGlobals.h"

Bullet::Bullet(const char* texturePath)
	: Projectile(texturePath)
{
}

Bullet::Bullet(const char* texturePath, const int columns, const int rows)
	: Projectile(texturePath, columns, rows)
{
}

Bullet::~Bullet()
{
	std::cout << "Bullet Removed \n";
}

void Bullet::Update(float deltaTime)
{
	SetPosX(GetPosX() + GetMoveSpeed() * deltaTime);

	if(static_cast<int>(GetPosX()) + GetWidth() > m_WindowWidth)
	{
		m_CanRemove = true;
		//std::cout << "CanRemove \n";
	}
}
