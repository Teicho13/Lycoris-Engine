#pragma once
#include "entt.hpp"

namespace Lycoris
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::registry& GetRegistry();

	private:
		entt::registry m_Registry;
	};
}

