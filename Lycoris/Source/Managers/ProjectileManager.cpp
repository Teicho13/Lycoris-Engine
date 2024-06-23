#include "./Managers/ProjectileManager.h"

#include "./R-Type/Entities/Projectile.h"
#include "./R-Type/Entities/Bullet.h"
#include "./R-Type/Entities/Player.h"

void ProjectileManager::Update(float deltaTime)
{
	for (int i = 0; i < m_Projectiles.size(); ++i)
	{
		if(m_Projectiles[i]->ShouldRemove())
		{
			m_Projectiles.erase(m_Projectiles.begin() + i);
			i--;
			continue;
		}

		m_Projectiles[i]->Update(deltaTime);
	}
}

void ProjectileManager::Render()
{
	for (const auto& projectile : m_Projectiles)
	{
		projectile->Draw();
	}
}

void ProjectileManager::ClearProjectiles()
{
	m_Projectiles.clear();
}

void ProjectileManager::AddBullet(Player* player)
{
	m_Projectiles.push_back(std::make_unique<Bullet>("Assets/Games/R-Type/Textures/Player/Bullet.png", 1, 1,player->GetPosX() + static_cast<float>(player->GetWidth()),player->GetPosY() + static_cast<float>(player->GetHeight()) / 2.f));
}
