#include "./managers/TextureManager.h"
#include "./Managers/ResourceManager.h"

#include <SDL_image.h>

void TextureManager::SetRenderer(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

SDL_Texture* TextureManager::CreateTexture(const char* texturePath)
{
	//Create texture
	SDL_Surface* surface = ResourceManager::GetInstance().GetSurface(texturePath);
	SDL_Texture* TempTexture = ResourceManager::GetInstance().GetTexture(texturePath);

	return TempTexture;
}

SDL_Texture* TextureManager::CreateTexture(const char* texturePath, int& imageWidth, int& imageHeight)
{
	//Create texture
	SDL_Surface* surface = ResourceManager::GetInstance().GetSurface(texturePath);
	SDL_Texture* TempTexture = ResourceManager::GetInstance().GetTexture(texturePath);

	imageWidth = surface->w;
	imageHeight = surface->h;

	return TempTexture;
}

void TextureManager::DeleteTexture(SDL_Texture* texture)
{
	SDL_DestroyTexture(texture);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_FRect* position)
{
	SDL_RenderCopyF(m_Renderer, texture, NULL, position);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_FRect* position)
{
	SDL_RenderCopyF(m_Renderer, texture, sourcePos, position);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* position)
{
	SDL_RenderCopy(m_Renderer, texture, NULL, position);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_Rect* position)
{
	SDL_RenderCopy(m_Renderer, texture, sourcePos, position);
}

void TextureManager::RenderBox(const float posX, const float posY, const float width, const float height)
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
	SDL_FRect tempRect = SDL_FRect(posX, posY, width, height);
	SDL_RenderDrawRectF(m_Renderer, &tempRect);
}


