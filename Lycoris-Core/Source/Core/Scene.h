#pragma once
#include "entt.hpp"

namespace Lycoris
{
	class Scene
	{
	public:
		Scene();
		~Scene();
	private:
		entt::registry m_Registry;
	};
}

