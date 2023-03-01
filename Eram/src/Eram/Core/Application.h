#pragma once

#include "Core.h"

#include "Eram/Core/Window.h"
#include "Eram/Core/LayerStack.h"
#include "Eram/Core/Events/Event.h"
#include "Eram/Core/Events/ApplicationEvent.h"

#include "Eram/Core/ImGui/ImGuiLayer.h"
#include "Eram/Scope/Scope.h"

namespace Eram {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		Scope* m_Scope;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

}