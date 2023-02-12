#include "erpch.h"
#include "Scope.h"

#include "Eram/Core/Renderer/Renderer.h"

#include <glad/glad.h>

namespace Eram {

	Scope::Scope()
		: m_Camera(-1.0f, 1.0f, -1.0f, 1.0f)
	{
	}

	void Scope::OnAttach()
	{
		m_TriangleVertexArray.reset(VertexArray::Create());

		float triangleVertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<VertexBuffer> triangleVertexBuffer; 
		triangleVertexBuffer.reset(VertexBuffer::Create(triangleVertices, sizeof(triangleVertices)));
		{
			BufferLayout triangleLayout = {
				{ ShaderDataType::Float3, "a_Postion" },
				{ ShaderDataType::Float4, "a_Color"},
			};
			triangleVertexBuffer->SetLayout(triangleLayout);
		}
		m_TriangleVertexArray->AddVertexBuffer(triangleVertexBuffer);

		unsigned int triangleIndicies[3] = { 0, 1, 2 };
		std::shared_ptr<IndexBuffer> triangleIndexBuffer;
		triangleIndexBuffer.reset(IndexBuffer::Create(triangleIndicies, 3));
		m_TriangleVertexArray->SetIndexBuffer(triangleIndexBuffer);

		std::string triangleVertexSrc = R"(
			#version 330 core 
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0f);

			}
		)";

		std::string triangleFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_TriangleShader.reset(Shader::Create(triangleVertexSrc, triangleFragmentSrc));
	}

	void Scope::OnUpdate()
	{
		RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		RenderCommand::Clear();

		m_Camera.SetPostion({ 0.25f, 0.0f, 0.0f });

		Renderer::BeginScene(m_Camera);
		Renderer::Submit(m_TriangleShader, m_TriangleVertexArray);
		Renderer::EndScene();
	}

	void Scope::OnEvent(Event& event)
	{

	}

}