#include "erpch.h"

#include "DebugWindow.h"

namespace Eram {


	void DebugWindow::OnImGuiRender()
	{
		ImGui::Begin("Debug Window");

		ImGui::SliderFloat("Backround Red", &m_BackroundRed, 0.0f, 1.0f, "%0.1f", 0);
		ImGui::SliderFloat("Backround Green", &m_BackroundGreen, 0.0f, 1.0f, "%0.1f", 0);
		ImGui::SliderFloat("Backround Blue", &m_BackroundBlue, 0.0f, 1.0f, "%0.1f", 0);
		ImGui::SliderFloat("Backround Alpha", &m_BackroundAlpha, 0.0f, 1.0f, "%0.1f", 0);

		ImGui::End();
	}
}