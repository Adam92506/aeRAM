#pragma once

#include "Eram/Core/Renderer/RendererAPI.h"

namespace Eram {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
		virtual void DrawLines(const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount) override;

		virtual void SetLineWidth(float width) override;
	};

}