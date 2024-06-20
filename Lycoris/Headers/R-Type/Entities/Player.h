#pragma once
#include "./Entities/Entity.h"

class Map;
class Camera;

class Player : public Entity
{
public:
	Player(const char* texturePath);
	Player(const char* texturePath, const int columns, const int rows);

	void Update(float deltaTime) override;
	bool HandleTileCollision(Map* map) const;

	void SetCamera(Camera* camera);
	Camera* GetCamera(Camera* camera) const;

	void HandleMovement(float dt);
	void HandleBoundChecks();

	void SetMovementSpeed(float amount);
	float GetMovementSpeed() const;

private:
	float m_MoveSpeed = 500.f;
	Camera* m_CamerRef = nullptr;
};
