#pragma once
#include <memory>
#include <vector>

class Projectile;

class ProjectileManager
{
public:
	ProjectileManager() = default;

	void Update(float deltaTime);
	void CheckBounds();
	void Render();


	void AddBullet();

private:
	std::vector<Projectile*> m_Projectiles;
};
