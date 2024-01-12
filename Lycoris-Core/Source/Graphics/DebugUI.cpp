#include "DebugUI.h"

#include <format>

#include "Graphics/Renderer.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "Core/Scene.h"
#include "Core/Components/Transform.h"

namespace Lycoris
{
	void DebugUI::Initialize()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGui_ImplGlfw_InitForOpenGL(Window::GetWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 450");
	}
	void DebugUI::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void DebugUI::Render(Scene* currentScene)
	{
		//ImGui::ShowDemoWindow();
		ImGui::Begin("ENNT Display");

		if (ImGui::CollapsingHeader("Entities"))
		{
			RenderEntities(currentScene);
		}

		ImGui::End();


		ImGui::Render();
	}

	void DebugUI::RenderEntities(Scene* currentScene)
	{
		//https://github.com/skypjack/entt/issues/88#issuecomment-1585923584

		auto view = currentScene->GetRegistry().view<entt::entity>();
		for (auto entity : view)
		{
			if (ImGui::CollapsingHeader("Entity"))
			{
				for (auto&& curr : currentScene->GetRegistry().storage())
				{
					entt::id_type cid = curr.first;
					auto& storage = curr.second;
					entt::type_info ctype = storage.type();

					if (storage.contains(entity)) {
						ImGui::Text(std::string(ctype.name()).c_str());
					}
				}
			}
		}
	}

	void DebugUI::NewFrame()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}
	void DebugUI::PostUpdate()
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}