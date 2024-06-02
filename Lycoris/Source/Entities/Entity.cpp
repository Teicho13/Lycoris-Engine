#include <SDL_rect.h>

#include "./Entities/Entity.h"
#include "./Core/Sprite.h"
#include "managers/TextureManager.h"


Entity::Entity(const char* texturePath)
{
	m_Sprite = new Sprite(texturePath);
}

Entity::~Entity()
{
	delete m_Sprite;
}

void Entity::Draw() const
{
	if(m_Sprite != nullptr)
	{
		const SDL_FRect tempRec(0, 0, static_cast<float>(m_Sprite->GetWidth()), static_cast<float>(m_Sprite->GetHeight()));

		TextureManager::RenderTexture(m_Sprite->GetTexture(), &tempRec);
	}

}

Sprite* Entity::GetSprite()
{
	return m_Sprite;
}
