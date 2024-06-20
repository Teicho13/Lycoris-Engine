#pragma once
#include <memory>
#include <vector>

class Projectile;

class ProjectileManager
{
public:
	ProjectileManager() = default;

	void Update(float deltaTime);
	void Render();
	void ClearProjectiles();


	void AddBullet();

private:
	std::vector<std::unique_ptr<Projectile>> m_Projectiles;
};
