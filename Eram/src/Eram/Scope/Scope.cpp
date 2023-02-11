#include "erpch.h"
#include "Scope.h"

#include <glad/glad.h>

namespace Eram {

	void Scope::OnAttach()
	{
		m_TriangleVertexArray.reset(VertexArray::Create());

		float triangleVertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<VertexBuffer> triangleVertexBuffer = std::make_shared<VertexBuffer>(VertexBuffer::Create(triangleVertices, sizeof(triangleVertices)));
		{
			BufferLayout triangleLayout = {
				{ ShaderDataType::Float3, "a_Postion" },
				{ ShaderDataType::Float4, "a_Color"},
			};
			triangleVertexBuffer->SetLayout(triangleLayout);
		}
		m_TriangleVertexArray->AddVertexBuffer(triangleVertexBuffer);

		unsigned int triangleIndicies[3] = { 0, 1, 2 };
		std::shared_ptr<IndexBuffer> triangleIndexBuffer = std::make_shared<IndexBuffer>(IndexBuffer::Create(triangleIndicies, 3));
		m_TriangleVertexArray->SetIndexBuffer(triangleIndexBuffer);

		float squareVerticies[4 * 3] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f
		};

		std::shared_ptr<VertexBuffer> squareVertexBuffer = std::make_shared<VertexBuffer>(VertexBuffer::Create(squareVerticies, sizeof(squareVerticies)));
		{
			BufferLayout squareLayout = {
				{ ShaderDataType::Float3, "a_Position" },
			};
			squareVertexBuffer->SetLayout(squareLayout);
		}
		m_SquareVertexArray->AddVertexBuffer(squareVertexBuffer);

		unsigned int squareIndecies[6] = {0, 1, 2, 2, 3, 0};
		std::shared_ptr<IndexBuffer> squareIndexBuffer = std::make_shared<IndexBuffer>(IndexBuffer::Create(squareIndecies, 6));
		m_SquareVertexArray->SetIndexBuffer(squareIndexBuffer);

		std::string triangleVertexSrc = R"(
			#version 330 core 
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);

				v_Color = a_Color;
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

		std::string squareVertexSrc = R"(
			#version 330 core 
			
			layout(location = 0) in vec3 a_Position;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string squareFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";

		m_TriangleShader.reset(Shader::Create(triangleVertexSrc, triangleFragmentSrc));
		m_SquareShader.reset(Shader::Create(squareVertexSrc, squareFragmentSrc));
	}

	void Scope::OnUpdate()
	{
		m_SquareShader->Bind();
		m_SquareVertexArray->Bind();
		glDrawElements(GL_TRIANGLES, m_SquareVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

		m_TriangleShader->Bind();
		m_TriangleVertexArray->Bind();
		glDrawElements(GL_TRIANGLES, m_TriangleVertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

}