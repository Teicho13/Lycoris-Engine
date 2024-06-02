#pragma once
#include <memory>

class Sprite;
class Entity
{
public:

	Entity(const char* texturePath);
	~Entity();

	void Draw() const;

	Sprite* GetSprite();
private:
	std::unique_ptr<Sprite> m_Sprite;
};
