#pragma once
#include <memory>
#include <vector>

class Entity;
class Projectile;
class EnemyManager
{
public:
	EnemyManager() = default;

	void Update(float deltaTime);
	void Draw() const;

	bool CheckBulletCollision(Projectile* bullet);

	void AddEntity(std::unique_ptr<Entity> entity);
	void ClearEntities();
private:
	std::vector<std::unique_ptr<Entity>> m_Enemies;
};
