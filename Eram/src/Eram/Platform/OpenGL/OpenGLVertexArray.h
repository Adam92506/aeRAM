#pragma once

#include "Eram/Core/Renderer/VertexArray.h"

namespace Eram {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();
		
		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer> vertexBuffer) override;
		virtual void AddIndexBuffer(const std::shared_ptr<IndexBuffer> indexBuffer) override;
	private:
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	private:
		uint32_t m_RendererID;
	};

}