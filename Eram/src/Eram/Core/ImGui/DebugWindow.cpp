#include "erpch.h"
#include "DebugWindow.h"

namespace Eram {

	DebugWindow::DebugWindow()
	{
		m_CameraPosition = { -74.17381457f, 40.68967472f };
	}

	void DebugWindow::OnImGuiRender()
	{
		ImGui::Begin("Debug Window");

		ImGui::SliderFloat("Camera X", &m_CameraPosition.x, -180.0f, 180.0f, "%0.8f", 0);
		ImGui::SliderFloat("Camera Y", &m_CameraPosition.y, -90.0f, 90.0f, "%0.8f", 0);
		if (ImGui::CollapsingHeader("Video Maps"))
		{
			for (int i = 0; i < m_VideoMaps->size(); i++)
			{
				ImGui::Checkbox((*m_VideoMaps)[i]->GetName().c_str(), (*m_VideoMaps)[i]->GetEnabled());
			}
		}

		ImGui::End();
	}
}