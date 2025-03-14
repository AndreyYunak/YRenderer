#include "YRendererCore/Scene.h"

namespace scene
{

	SceneMenu::SceneMenu(Scene*& CurrentScenePointer)
		: m_CurrentScene(CurrentScenePointer) {}

	void SceneMenu::onRender()
	{
	}
	void SceneMenu::onUpdate(float deltaTime)
	{
	}
	void SceneMenu::onImGuiRender()
	{
		ImGui_ImplOpenGL3_NewFrame();
    	ImGui_ImplGlfw_NewFrame();
    	ImGui::NewFrame();
		for (auto& scene : m_Scene)
		{
			if (ImGui::Button(scene.first.c_str()))
				m_CurrentScene = scene.second();
		}
		ImGui::Render();
    	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}