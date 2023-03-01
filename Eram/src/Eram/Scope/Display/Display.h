#pragma once

#include "Eram/Core/Layer.h"
#include "Eram/Core/Renderer/CameraController.h"

#include "Eram/Scope/VideoMap.h"

namespace Eram {

	class Display
	{
	public:
		Display(float width, float height);
		virtual ~Display() {}

		void Init();
		void OnUpdate();
		void OnResize(float width, float height);
	private:
		CameraController m_CameraController;

		float m_Width, m_Height;
	};

}