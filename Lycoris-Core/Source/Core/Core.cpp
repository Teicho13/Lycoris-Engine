#include "Core.h"
#include "Graphics/Renderer.h"

#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <iostream>

namespace Core {

	void Initialize()
	{
		std::cout << "Booting up Lycoris...!\n";
		std::cout << "Initializing Window!\n";
		Lycoris::Renderer::Initialize();

		std::cout << "Initializing ImGui!\n";
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		
		ImGui_ImplGlfw_InitForOpenGL(Lycoris::Window::GetWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 450");



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