#include "erpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Eram/Core.h"
#include "Eram/Log.h"

namespace Eram {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ER_ASSERT(windowHandle, "Window handle is null")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ER_ASSERT(status, "Failed to initialize Glad");

		ER_INFO("OpenGL Info:");
		ER_INFO("   Vendor: {0}", (char*)glGetString(GL_VENDOR));
		ER_INFO("   Renderer: {0}", (char*)glGetString(GL_RENDERER));
		ER_INFO("   Version: {0}", (char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}