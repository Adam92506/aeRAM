#include "erpch.h"
#include "Scope.h"

#include "Eram/Core/Renderer/Renderer.h"

#include "Eram/ResourceManager/Sct2Parser.h"

namespace Eram {

	Scope::Scope()
		: m_Camera(-3.4f, 3.4f, -2.0f, 2.0f)
	{
	}

	void Scope::OnAttach()
	{
		Sct2Parser::LoadMapsFromFile(m_VideoMaps, "Test.sct2");

		for (int i = 0; i < m_VideoMaps.size(); i++)
		{
			m_VideoMaps[i]->Init();
		}
	}

	void Scope::OnUpdate()
	{
		RenderCommand::SetClearColor({ 0.01f, 0.04f, 0.12f, 1.0f });
		RenderCommand::Clear();

		Renderer::BeginScene(m_Camera);

		m_Camera.SetRotation(13.3);

		for (int i = 0; i < m_VideoMaps.size(); i++)
		{
			if (m_VideoMaps[i]->IsEnabled())
			{
				m_VideoMaps[i]->DrawVideoMap();
			}
		}

		Renderer::EndScene();
	}

	void Scope::OnEvent(Event& event)
	{

	}

}