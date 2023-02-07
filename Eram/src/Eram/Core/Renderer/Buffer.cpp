#include "erpch.h"
#include "Buffer.h"

#ifdef ER_PLATFORM_WINDOWS
#include "Eram/Platform/OpenGL/OpenGLBuffer.h"
#endif

namespace Eram {

	VertexBuffer* VertexBuffer::Create(float* verticies, uint32_t size)
	{
		#ifdef ER_PLATFORM_WINDOWS
			return new OpenGLVertexBuffer(verticies, size);
		#else
			ER_ASSERT(false, "Renderer: No supported rendering API")
			return nullptr;
		#endif
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indecies, uint32_t count)
	{
		#ifdef ER_PLATFORM_WINDOWS
			return new OpenGLIndexBuffer(indecies, count);
		#else
			ER_ASSERT(false, "Renderer: No supported rendering API")
			return nullptr;
		#endif
	}

}