#pragma once

namespace Lycoris
{
	class DebugUI
	{
	public:
		static void Initialize();
		static void Shutdown();

		static void Render();

		static void NewFrame();
		static void PostUpdate();
	};
}

