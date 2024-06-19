#include "./Managers/ProjectileManager.h"

#include "R-Type/Entities/Projectile.h"
#include "./R-Type/Entities/Bullet.h"

void ProjectileManager::Update(float deltaTime)
{
	for (auto projectile : m_Projectiles)
	{
		projectile->Update(deltaTime);
	}
}

void ProjectileManager::Render()
{
	for (auto projectile : m_Projectiles)
	{
		projectile->Draw();
	}
}

void ProjectileManager::AddBullet()
{
	m_Projectiles.emplace_back(new Bullet("Assets/Games/R-Type/Textures/Player/Bullet.png", 1, 1));
}
