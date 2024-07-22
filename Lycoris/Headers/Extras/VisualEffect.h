#pragma once
#include <memory>
#include "./Core/Animation.h"


class Sprite;
class VisualEffect
{
public:
	VisualEffect(const char* texturePath, const int columns, const int rows, float posX, float posY, bool looping);
	void Callback();
	void Draw();
	void Update();
	Sprite* GetSprite() const;

private:
	Animation m_Animation;
	std::unique_ptr<Sprite> m_Sprite;

	float m_PosX = 0.f;
	float m_PosY = 0.f;
	int m_Width = 0;
	int m_Height = 0;
};
