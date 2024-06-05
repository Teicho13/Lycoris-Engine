#pragma once
#include <memory>

class Sprite;
class Entity
{
public:

	Entity(const char* texturePath);
	Entity(const char* texturePath, const int columns, const int rows);
	~Entity() = default;

	void Draw() const;

	Sprite* GetSprite();
private:
	std::unique_ptr<Sprite> m_Sprite;
};
