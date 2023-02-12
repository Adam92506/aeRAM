#pragma once

#include "Eram/Core/Renderer/Shader.h"

namespace Eram {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind();
		virtual void Unbind();

		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& uniform) override;
	private:
		uint32_t m_RendererID;
	};

}