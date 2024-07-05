#include "./Managers/ResourceManager.h"

#include <SDL_surface.h>
#include <SDL_render.h>
#include <SDL_image.h>

ResourceManager& ResourceManager::GetInstance()
{
	static ResourceManager rm;
	return rm;
}

void ResourceManager::SetRenderer(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

SDL_Surface* ResourceManager::GetSurface(const std::string& filePath)
{
	//Look for surface
	auto search = m_Surfaces.find(filePath);
	if(search != m_Surfaces.end())
	{
		//Return existing surface
		return m_Surfaces[filePath];
	}

	//Create new Surface and add to the list
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	m_Surfaces.insert(std::make_pair(filePath,surface));
	return m_Surfaces[filePath];
}

SDL_Texture* ResourceManager::GetTexture(const std::string &filePath)
{
	auto search = m_Textures.find(filePath);
	if (search != m_Textures.end())
	{
		return m_Textures[filePath];
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, GetSurface(filePath));
	m_Textures.insert(std::make_pair(filePath, texture));
	return m_Textures[filePath];
}
