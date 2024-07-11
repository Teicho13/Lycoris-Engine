#include "./R-Type/Entities/Enemies/Patapata.h"

#include <SDL_timer.h>
#include "./Core/Sprite.h"

Patapata::Patapata(const char* texturePath, const int columns, const int rows)
	: Entity(texturePath, columns, rows)
{
	SetIsAnimated(true);
	SetFrameDelay(100);
}

Patapata::Patapata(const char* texturePath, const int columns, const int rows, float posX, float posY)
	: Entity(texturePath, columns, rows,posX,posY)
{
	SetIsAnimated(true);
	SetFrameDelay(100);
	m_StartX = posX;
	m_StartY = posY;
}

void Patapata::Update(float deltaTime)
{
	Animate();
	Move(deltaTime);
}

void Patapata::Move(float dt)
{
	//Move based on sine wave offset by the Y start position
	float sine = (m_WaveFrequency * sinf(static_cast<float>(static_cast<double>(SDL_GetTicks()) * 0.5 * M_PI / m_WaveSpeed)) + m_StartY);
	SetPosY(sine);

	SetPosX(GetPosX() - (m_MoveSpeed * dt));

}
