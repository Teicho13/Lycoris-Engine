#include "./Core/Sprite.h"

#include "managers/TextureManager.h"
#include <SDL_rect.h>

Sprite::Sprite(const char* texturePath)
{
	m_Texture = TextureManager::CreateTexture(texturePath, m_SpriteWidth, m_SpriteHeight);
}

Sprite::~Sprite()
{
	TextureManager::DeleteTexture(m_Texture);
}

SDL_Texture* Sprite::GetTexture() const
{
	return m_Texture;
}

int Sprite::GetWidth() const
{
	return m_SpriteWidth;
}

int Sprite::GetHeight() const
{
	return m_SpriteHeight;
}
