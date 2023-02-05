#pragma once

#include "Eram/Renderer/Shader.h"

namespace Eram {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind();
		virtual void Unbind();
	private:
		uint32_t m_RendererID;
	};

}