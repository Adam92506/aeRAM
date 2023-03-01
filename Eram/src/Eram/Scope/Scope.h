#pragma once

#include "Eram/Core/Layer.h"
#include "Eram/Scope/Display/Display.h"

namespace Eram {

	class Scope : public Layer
	{
	public:
		Scope(float displayWidth, float displayHeight);
		virtual ~Scope() {}
		
		virtual void OnAttach() override;
		virtual void OnUpdate(Timestep ts) override;
		virtual void OnEvent(Event& event) override;
	private:
		std::shared_ptr<Display> m_Display;
	};

}