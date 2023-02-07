#pragma once

#include "Core.h"

#include "Eram/Core/Window.h"
#include "Eram/Core/LayerStack.h"
#include "Eram/Core/Events/Event.h"
#include "Eram/Core/Events/ApplicationEvent.h"

#include "Eram/Core/ImGui/ImGuiLayer.h"
#include "Eram/Core/ImGui/DebugWindow.h"

#include "Eram/Core/Renderer/Shader.h"
#include "Eram/Core/Renderer/Buffer.h"
#include "Eram/Core/Renderer/VertexArray.h"

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

		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

}