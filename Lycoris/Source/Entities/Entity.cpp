#include <SDL_rect.h>

#include "./Entities/Entity.h"
#include "./Core/Sprite.h"
#include "managers/TextureManager.h"


Entity::Entity(const char* texturePath)
{
	m_Sprite.reset(new Sprite(texturePath));
}

Entity::Entity(const char* texturePath, const int columns, const int rows)
{
	m_Sprite.reset(new Sprite(texturePath,columns,rows));
}

void Entity::Draw() const
{
	if(m_Sprite != nullptr)
	{
		//Create Variable for the position of the sprite
		const SDL_FRect tempRec(0, 0, static_cast<float>(m_Sprite->GetWidth()), static_cast<float>(m_Sprite->GetHeight()));

		//Create temp variable to get the position / size that needs to be rendered
		SDL_Rect tempSource;
		m_Sprite->GetSourceRec(tempSource);

		TextureManager::RenderTexture(m_Sprite->GetTexture(), &tempSource, &tempRec);
	}

}

Sprite* Entity::GetSprite()
{
	return m_Sprite.get();
}
