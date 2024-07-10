#include "./R-Type/Entities/Enemies/Patapata.h"
#include "./Core/Sprite.h"

Patapata::Patapata(const char* texturePath, const int columns, const int rows)
	: Entity(texturePath, columns, rows)
{
	SetIsAnimated(true);
	SetFrameDelay(100);
}

void Patapata::Update(float deltaTime)
{
	Animate();
}
