#include "./R-Type/Entities/Player.h"

#include <iostream>
#include <SDL_timer.h>

#include "./Core/Sprite.h"

#include "./Core/Utility/KeyStates.h"
#include "./Core/Utility/AppGlobals.h"
#include "R-Type/Map/Camera.h"
#include "R-Type/Map/Map.h"
#include "R-Type/Map/Tile.h"


Player::Player(const char* texturePath)
	: Entity(texturePath)
{
	SetWidth(GetWidth() - 10);
	SetHeight(GetHeight() - 10);
}

Player::Player(const char* texturePath, const int columns, const int rows)
	: Entity(texturePath,columns,rows)
{
	SetWidth(GetWidth() - 10);
	SetHeight(GetHeight() - 10);
}

void Player::Update(float deltaTime)
{
	HandleMovement(deltaTime);
	HandleBoundChecks();
}

bool Player::HandleTileCollision(Map* map) const
{
	if(m_CamerRef == nullptr)
		return false;


	int posX = (static_cast<int>(GetPosX() + m_CamerRef->GetPosX())) / 64;
	int posX2 = (static_cast<int>(GetPosX() + m_CamerRef->GetPosX()) + GetWidth()) / 64;

	int posY = static_cast<int>(GetPosY() / 64);
	int posY2 = (static_cast<int>(GetPosY()) + GetHeight()) / 64;

	if (posY2 > (Map::m_MapRows - 1))
		posY2 = 11;

	if(map->HasTileCollision(posX, posX2, posY, posY2))
	{
		return true;
	}

	return false;
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
