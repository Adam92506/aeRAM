#pragma once

#include <glm/glm.hpp>
#include "Eram/Core/Renderer/VertexArray.h"

namespace Eram {

	class RendererAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;
		virtual void DrawLines(const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount) = 0;

		virtual void SetLineWidth(float width) = 0;
	};

}