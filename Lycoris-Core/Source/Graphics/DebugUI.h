#pragma once

namespace Lycoris
{
	class Scene;

	class DebugUI
	{
	public:
		static void Initialize();
		static void Shutdown();

		static void Render(Scene* currentScene);

		static void RenderEntities(Scene* currentScene);

		static void NewFrame();
		static void PostUpdate();
	};
}

