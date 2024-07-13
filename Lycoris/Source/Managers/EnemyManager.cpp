#include "./Managers/EnemyManager.h"
#include "./Entities/Entity.h"
#include "./R-Type/Entities/Projectile.h"

void EnemyManager::Update(float deltaTime)
{
	for (int i = 0; i < m_Enemies.size(); ++i)
	{
		if (m_Enemies[i]->ShouldRemove())
		{
			m_Enemies.erase(m_Enemies.begin() + i);
			i--;
			continue;
		}

		m_Enemies[i]->Update(deltaTime);
	}
}

void EnemyManager::Draw() const
{
	for (const auto& entity : m_Enemies)
	{
		entity->Draw();
	}
}

bool EnemyManager::CheckBulletCollision(Projectile* bullet)
{
	for (auto& enemy : m_Enemies)
	{
		//We do a simple AABB
		if (enemy->GetPosX() + static_cast<float>(enemy->GetWidth()) >= bullet->GetPosX() &&
			bullet->GetPosX() + static_cast<float>(bullet->GetWidth()) >= enemy->GetPosX() &&
			enemy->GetPosY() + static_cast<float>(enemy->GetHeight()) >= bullet->GetPosY() &&
			bullet->GetPosY() + static_cast<float>(bullet->GetHeight()) >= enemy->GetPosY())
		{
			enemy->SetCanDie();
			return true;
		}

		return false;
	}

	return false;
}

void EnemyManager::AddEntity(std::unique_ptr<Entity> entity)
{
	m_Enemies.push_back(std::move(entity));
}

void EnemyManager::ClearEntities()
{
	m_Enemies.clear();
}
