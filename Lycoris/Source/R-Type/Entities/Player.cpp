#include "./R-Type/Entities/Player.h"
#include "./Core/Sprite.h"

#include "./Core/Utility/KeyStates.h"
#include "./Core/Utility/AppGlobals.h"


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
