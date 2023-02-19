#pragma once

#include "Eram/Core/Renderer/VertexArray.h"
#include "Eram/Core/Renderer/Shader.h"

#include <glm/glm.hpp>

namespace Eram {

	class VideoMap
	{
	public:
		VideoMap(std::string name);

		void Init();

		void DrawVideoMap() const;

		inline const std::string& GetName() const { return m_Name; };
		inline bool IsEnabled() { return m_IsEnabled; }
		inline bool* GetEnabled() { return &m_IsEnabled; }

		inline void SetEnabled(bool enabled) { m_IsEnabled = enabled; }

		void AddVertex(glm::vec2 vertex) { m_Verticies.push_back(vertex); }
	private:
		std::string whiteVertexSrc = R"(
			#version 330 core 
			layout(location = 0) in vec2 a_Position;

			uniform mat4 u_ViewProjection;

			void main()
			{
				gl_Position = u_ViewProjection * vec4(a_Position, 0.0f, 1.0f);
			}
		)";

		std::string whiteFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			void main()
			{
				color = vec4(0.29f, 0.29f, 0.29f, 1.0f);
			}
		)";
	private:
		std::string m_Name;
		bool m_IsEnabled = false;

		std::vector<glm::vec2> m_Verticies;

		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_WhiteShader;
	};

}