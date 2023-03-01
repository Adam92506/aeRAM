#include "erpch.h"
#include "Scope.h"

namespace Eram {

	Scope::Scope(float displayWidth, float displayHeight)
	{
		m_Display.reset(new Display(displayWidth, displayHeight));
	}

	void Scope::OnAttach()
	{
		m_Display->Init();
	}

	void Scope::OnUpdate(Timestep ts)
	{
		m_Display->OnUpdate();
	}

	void Scope::OnEvent(Event& event)
	{
		if (event.GetEventType() == EventType::WindowResize)
		{
			auto& resizeEvent = (WindowResizeEvent&)event;

			m_Display->OnResize(resizeEvent.GetWidth(), resizeEvent.GetHeight());
		}
	}

}