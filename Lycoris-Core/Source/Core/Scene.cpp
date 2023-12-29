#include "Scene.h"
#include "entt.hpp"
#include "Components/Transform.h"

#include <iostream>

namespace Lycoris
{
	Scene::Scene() 
	{
		//Create Entity
		entt::entity entity = m_Registry.create();

		//Add component to entity
		m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));

		//Create Entity 2
		entt::entity entity2 = m_Registry.create();
		m_Registry.emplace<TransformComponent>(entity2, glm::mat4(1.0f));

		//Get all components with transform component
		auto view = m_Registry.view<TransformComponent>();
		for (auto entity : view)
		{
			std::cout << "Entity with transform component\n";
		}
	}

	Scene::~Scene()
	{
	}

}