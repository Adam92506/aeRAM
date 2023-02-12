#pragma once

#include <string>
#include <glm/glm.hpp>

namespace Eram {

	class Shader
	{
	public:
		virtual ~Shader() {};

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) = 0;

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}