#pragma once
#include <memory>
#include <vector>

class Entity;
class EnemyManager
{
public:
	EnemyManager() = default;

	void Update(float deltaTime) const;
	void Draw() const;

	void AddEntity(std::unique_ptr<Entity> entity);
	void ClearEntities();
private:
	std::vector<std::unique_ptr<Entity>> m_Entities;
};
