#include "erpch.h"
#include "DebugWindow.h"

namespace Eram {

	DebugWindow::DebugWindow()
	{
		m_BackroundColor = { 0, 0, 0 ,0 };
	}

	void DebugWindow::OnImGuiRender()
	{
		ImGui::Begin("Debug Window");

		ImGui::SliderFloat("Backround Red", &m_BackroundColor.r, 0.0f, 1.0f, "%0.2f", 0);
		ImGui::SliderFloat("Backround Green", &m_BackroundColor.g, 0.0f, 1.0f, "%0.2f", 0);
		ImGui::SliderFloat("Backround Blue", &m_BackroundColor.b, 0.0f, 1.0f, "%0.2f", 0);
		ImGui::SliderFloat("Backround Alpha", &m_BackroundColor.a, 0.0f, 1.0f, "%0.2f", 0);

		ImGui::End();
	}
}