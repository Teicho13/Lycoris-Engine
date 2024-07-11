#include "./Managers/EnemyManager.h"
#include "./Entities/Entity.h"

void EnemyManager::Update(float deltaTime) const
{
	for (auto const& entity : m_Entities)
	{
		entity->Update(deltaTime);
	}
}

void EnemyManager::Draw() const
{
	for (const auto& entity : m_Entities)
	{
		entity->Draw();
	}
}

void EnemyManager::AddEntity(std::unique_ptr<Entity> entity)
{
	m_Entities.push_back(std::move(entity));
}

void EnemyManager::ClearEntities()
{
	m_Entities.clear();
}
