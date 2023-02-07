#pragma once

#include "Eram/Core/Layer.h"
#include "Eram/Core/Events/KeyEvent.h"
#include "Eram/Core/Events/MouseEvent.h"
#include "Eram/Core/Events/ApplicationEvent.h"

namespace Eram {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}