#pragma once
#include <memory>

class Sprite;
class Entity
{
public:

	Entity(const char* texturePath);
	Entity(const char* texturePath, const int columns, const int rows);
	Entity(const char* texturePath, const int columns, const int rows, float posX, float posY);

	virtual ~Entity() = default;

	void Draw() const;
	virtual void Update(float deltaTime) = 0;

	void SetPosX(float pos);
	void SetPosY(float pos);

	void SetWidth(int width);
	void SetHeight(int height);

	float GetPosX() const;
	float GetPosY() const;
	void GetPosXY(float& posX, float& posY) const;

	int GetWidth() const;
	int GetHeight() const;

	void Animate() const;

	void SetIsAnimated(bool value);
	void SetFrameDelay(int delay);

	bool GetIsAnimated() const;
	int GetFrameDelay() const;

	Sprite* GetSprite() const;

private:
	std::unique_ptr<Sprite> m_Sprite;

	float m_PosX = 0.f;
	float m_PosY = 0.f;
	int m_Width = 0;
	int m_Height = 0;

	bool m_IsAnimated = false;
	//Delay in ms
	int m_FrameDelay = 100;
};
