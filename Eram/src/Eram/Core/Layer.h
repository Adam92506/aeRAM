#pragma once

#include "Eram/Core/Core.h"
#include "Eram/Core/Events/Event.h"

namespace Eram {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}