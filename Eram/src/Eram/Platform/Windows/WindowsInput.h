#pragma once

#include "Eram/Core/Input.h"

namespace Eram {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int keycode) override;
		virtual std::pair<float, float> GetMousePosImpl();
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}