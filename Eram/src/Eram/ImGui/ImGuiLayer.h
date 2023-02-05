#pragma once

#include "Eram/Layer.h"
#include "Eram/Events/KeyEvent.h"
#include "Eram/Events/MouseEvent.h"
#include "Eram/Events/ApplicationEvent.h"

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