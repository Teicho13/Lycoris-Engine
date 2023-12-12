#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

namespace Lycoris
{
	class Window
	{
	public: 
		static int Create();
		static void Destroy();

		static void Clear();

		static void Update();

		static void Display();

		static bool IsOpen();

		static void Close();

		static void PollEvents();

		static GLFWwindow* GetWindow();
	};
}

