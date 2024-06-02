#pragma once

class Sprite;
class Entity
{
public:

	Entity(const char* texturePath);
	~Entity();

	void Draw() const;

	Sprite* GetSprite();
private:
	Sprite* m_Sprite;
};
