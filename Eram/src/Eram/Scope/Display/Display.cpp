#include "erpch.h"
#include "Display.h"

#include "Eram/Core/Renderer/Renderer.h"
#include "Eram/Core/Renderer/RenderCommand.h"

namespace Eram {

	
	Display::Display(float width, float height)
		: m_Width(width), m_Height(height), m_CameraController(m_Width / m_Height)
	{
	}

	void Display::Init()
	{

	}

	void Display::OnUpdate()
	{

	}

	void Display::OnResize(float width, float height)
	{
		m_Width = width;
		m_Height = height;
		m_CameraController.OnResize(width, height);
	}

}