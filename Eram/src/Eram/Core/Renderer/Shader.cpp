#include "erpch.h"
#include "Shader.h"

#ifdef ER_PLATFORM_WINDOWS
#include "Eram/Platform/OpenGL/OpenGLShader.h"
#endif

namespace Eram {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		#ifdef ER_PLATFORM_WINDOWS
			return new OpenGLShader(vertexSrc, fragmentSrc);
		#else
			ER_ASSERT(false, "Renderer: No supported rendering API")
			return nullptr;
		#endif
	}



}