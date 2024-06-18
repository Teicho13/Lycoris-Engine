#include "./R-Type/Entities/Player.h"

#include <iostream>

#include "./Core/Sprite.h"

#include "./Core/Utility/KeyStates.h"
#include "./Core/Utility/AppGlobals.h"
#include "R-Type/Map/Camera.h"
#include "R-Type/Map/Map.h"
#include "R-Type/Map/Tile.h"


Player::Player(const char* texturePath)
	: Entity(texturePath)
{
}

Player::Player(const char* texturePath, const int columns, const int rows)
	: Entity(texturePath,columns,rows)
{

}

void Player::Update(float deltaTime)
{
	HandleMovement(deltaTime);
	HandleBoundChecks();
}

void Player::HandleTileCollision(Map* map)
{
	if(m_CamerRef == nullptr)
		return;


	int posX = (static_cast<int>(GetPosX() + m_CamerRef->GetPosX())) / 64;
	int posX2 = (static_cast<int>(GetPosX() + m_CamerRef->GetPosX()) + GetWidth()) / 64;

	int posY = static_cast<int>(GetPosY() / 64);
	int posY2 = (static_cast<int>(GetPosY()) + GetHeight()) / 64;

	if (posY2 > (Map::m_MapRows - 1))
		posY2 = 11;

	if (map->CanTileCollide(map->GetTile(posY, posX)))
	{
		std::cout << "Collide 1 \n";
	}
	if (map->CanTileCollide(map->GetTile(posY, posX2)))
	{
		std::cout << "Collide 2 \n";
	}
	if (map->CanTileCollide(map->GetTile(posY2, posX)))
	{
		std::cout << "Collide 3 \n";
	}
	if (map->CanTileCollide(map->GetTile(posY2, posX2)))
	{
		std::cout << "Collide 4 \n";
	}
}

void Player::SetCamera(Camera* camera)
{
	m_CamerRef = camera;
}

Camera* Player::GetCamera(Camera* camera) const
{
	return m_CamerRef;
}

void Player::HandleMovement(float dt)
{
	if(g_KeyStates[SDL_SCANCODE_A])
	{
		SetPosX(GetPosX() + -m_MoveSpeed * dt);
	}

	if(g_KeyStates[SDL_SCANCODE_D])
	{
		SetPosX(GetPosX() + m_MoveSpeed * dt);
	}

	if(g_KeyStates[SDL_SCANCODE_W])
	{
		SetPosY(GetPosY() + -m_MoveSpeed * dt);
	}

	if(g_KeyStates[SDL_SCANCODE_S])
	{
		SetPosY(GetPosY() + m_MoveSpeed * dt);
	}
}

void Player::HandleBoundChecks()
{
	if(GetPosY() <= 0)
	{
		SetPosY(0);
	}

	if(GetPosX() <= 0)
	{
		SetPosX(0);
	}

	if(static_cast<int>(GetPosY()) + GetHeight() >= m_WindowHeight)
	{
		SetPosY(static_cast<float>(m_WindowHeight - GetHeight()));
	}

	if(static_cast<int>(GetPosX()) + GetWidth() >= m_WindowWidth)
	{
		SetPosX(static_cast<float>(m_WindowWidth - GetWidth()));
	}
}

void Player::SetMovementSpeed(float amount)
{
	m_MoveSpeed = amount;
}

float Player::GetMovementSpeed() const
{
	return m_MoveSpeed;
}
