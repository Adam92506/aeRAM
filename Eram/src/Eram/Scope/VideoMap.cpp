#include "erpch.h"
#include "VideoMap.h"

#include "Eram/Core/Renderer/Renderer.h"

#include "Eram/Core/Log.h"
#include "Eram/Core/Utill.h"

namespace Eram {

	VideoMap::VideoMap(std::string name)
		: m_Name(name)
	{
		m_WhiteShader.reset(Shader::Create(whiteVertexSrc, whiteFragmentSrc));
	}

	void VideoMap::Init()
	{
		m_VertexArray.reset(VertexArray::Create());

		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create((const char *)m_Verticies.data(), m_Verticies.size() * sizeof(glm::vec2)));
		vertexBuffer->SetLayout({
			{ ShaderDataType::Float2, "a_Position" },
		});
		m_VertexArray->AddVertexBuffer(vertexBuffer);
	}

	void VideoMap::DrawVideoMap() const
	{
		Renderer::Submit(ER_LINES, m_WhiteShader, m_VertexArray, m_Verticies.size());
	}

}