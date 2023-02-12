#include "erpch.h"
#include "RenderCommand.h"

#include "Eram/Platform/OpenGL/OpenGLRendererAPI.h"

namespace Eram {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}