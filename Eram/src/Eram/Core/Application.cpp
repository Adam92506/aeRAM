#include "erpch.h"
#include "Application.h"

#include "Eram/Core/Log.h"
#include "Eram/Core/Input.h"
#include "Eram/Core/Keycodes.h"

#include <glad/glad.h>

namespace Eram {
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		(!s_Instance, "Application already exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(ER_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer;
		PushOverlay(m_ImGuiLayer);

		m_DebugWindow = new DebugWindow;
		PushOverlay(m_DebugWindow);

		m_Scope = new Scope();
		PushLayer(m_Scope);

		m_DebugWindow->SetVideoMaps(m_Scope->GetVideoMaps());
	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(ER_BIND_EVENT_FN(Application::OnWindowClosed));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Scope->SetCameraPosition(m_DebugWindow->GetCameraPosition());

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}