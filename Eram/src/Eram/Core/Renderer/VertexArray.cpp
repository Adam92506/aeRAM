#include "erpch.h"
#include "VertexArray.h"

#ifdef ER_PLATFORM_WINDOWS
#include "Eram/Platform/OpenGL/OpenGLVertexArray.h"
#endif

namespace Eram {

	VertexArray* VertexArray::Create()
	{
		#ifdef ER_PLATFORM_WINDOWS
			return new OpenGLVertexArray();
		#else
			ER_ASSERT(false, "Renderer: No supported rendering API")
			return nullptr;
		#endif
	}

}