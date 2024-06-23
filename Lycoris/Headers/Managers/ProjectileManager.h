#pragma once
#include <memory>
#include <vector>

class Projectile;
class Player;

class ProjectileManager
{
public:
	ProjectileManager() = default;

	void Update(float deltaTime);
	void Render();
	void ClearProjectiles();


	void AddBullet(Player* player);

private:
	std::vector<std::unique_ptr<Projectile>> m_Projectiles;
};
