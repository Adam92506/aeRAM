#include "erpch.h"
#include "CameraController.h"

#include "Eram/Core/Renderer/Camera.h"

namespace Eram {

	CameraController::CameraController(float aspectRatio)
		: m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel)
	{
	}

	void CameraController::OnUpdate(Timestep ts)
	{
	}

	void CameraController::OnEvent(Event& e)
	{
	}

	void CameraController::OnResize(float width, float height)
	{
		m_AspectRatio = width / height;
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}

	void CameraController::SetZoomLevel(float zoomLevel)
	{
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}
}