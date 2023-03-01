#pragma once

#include "Eram/Core/Renderer/Camera.h"

#include "Eram/Core/Events/ApplicationEvent.h"
#include "Eram/Core/Events/MouseEvent.h"
#include "Eram/Core/Timestep.h"

namespace Eram {

	class CameraController
	{
	public:
		CameraController(float aspectRatio);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		void OnResize(float width, float height);

		Camera& GetCamera() { return m_Camera; }
		const Camera& GetCamera() const { return m_Camera; }

		float GetZoomLevel() { return m_ZoomLevel; }
		void SetZoomLevel(float zoomLevel);

		float GetRotation() { return m_CameraRotation; }
		void SetRotation(float rotation)
		{
			m_CameraRotation = rotation;
			m_Camera.SetRotation(m_CameraRotation);
		}
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		Camera m_Camera;

		glm::vec2 m_CameraPosition = { 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;
	};

}