#include "Core.h"
#include "Graphics/Renderer.h"
#include "Graphics/DebugUI.h"
#include "Scene.h"

#include <iostream>

namespace Core {

	Lycoris::Scene* scene;

	void Initialize()
	{
		std::cout << "Booting up Lycoris...!\n";
		std::cout << "Initializing Window!\n";
		Lycoris::Renderer::Initialize();

		std::cout << "Initializing ImGui!\n";
		Lycoris::DebugUI::Initialize();
		
		std::cout << "Creating new Scene!\n";
		scene = new Lycoris::Scene();

		Update();
	}

	void Update()
	{
			
		while(Lycoris::Window::IsOpen())
		{
			Lycoris::Window::PollEvents();

			Lycoris::DebugUI::NewFrame();

			Lycoris::DebugUI::Render(scene);

			Lycoris::Window::Update();

			Lycoris::DebugUI::PostUpdate();

			Lycoris::Window::Display();
		}

		Shutdown();
	}

	void Shutdown() {
		Lycoris::DebugUI::Shutdown();
	}

}