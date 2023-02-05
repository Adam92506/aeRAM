#pragma once

#include "Core.h"

#include "Window.h"
#include "Eram/LayerStack.h"
#include "Eram/Events/Event.h"
#include "Eram/Events/ApplicationEvent.h"

#include "Eram/ImGui/ImGuiLayer.h"
#include "Eram/ImGui/DebugWindow.h"

#include "Eram/Renderer/Shader.h"
#include "Eram/Renderer/Buffer.h"

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
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		DebugWindow* m_DebugWindow;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

}