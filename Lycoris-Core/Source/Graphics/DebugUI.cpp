#include "DebugUI.h"
#include "Graphics/Renderer.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

namespace Lycoris
{
	void DebugUI::Initialize()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGui_ImplGlfw_InitForOpenGL(Window::GetWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 450");
	}
}