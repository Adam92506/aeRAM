#include "erpch.h"
#include "Renderer.h"

namespace Eram {

	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

	void Renderer::BeginScene(Camera& camera)
	{
		m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(int primitive, const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount)
	{
		switch (primitive)
		{
			case ER_NONE: return;
			case ER_TRIANGLE:
			{
				shader->Bind();
				shader->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
				vertexArray->Bind();
				RenderCommand::DrawIndexed(vertexArray);
			}
			case ER_LINES:
			{
				shader->Bind();
				shader->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
				vertexArray->Bind();
				RenderCommand::DrawLines(vertexArray, vertexCount);
			}
			case ER_LINE_STRIP: return;
			case ER_LINE_LOOP: return;
		}
	}

}