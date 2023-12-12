#include "Core.h"
#include "Graphics/Renderer.h"
#include "Graphics/DebugUI.h"


#include <iostream>

namespace Core {

	void Initialize()
	{
		std::cout << "Booting up Lycoris...!\n";
		std::cout << "Initializing Window!\n";
		Lycoris::Renderer::Initialize();

		std::cout << "Initializing ImGui!\n";
		Lycoris::DebugUI::Initialize();



		Update();
	}

	void Update()
	{
			
		while(Lycoris::Window::IsOpen())
		{
			Lycoris::Window::Update();
		}
	}

}