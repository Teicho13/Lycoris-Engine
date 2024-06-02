#pragma once

struct SDL_Texture;

class Sprite
{
public:
	Sprite(const char* texturePath);
	~Sprite();

	SDL_Texture* GetTexture() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	SDL_Texture* m_Texture = nullptr;
	int m_SpriteWidth = 0;
	int m_SpriteHeight = 0;
};
