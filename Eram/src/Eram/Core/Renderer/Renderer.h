#pragma once

#include "Eram/Core/Renderer/Camera.h"
#include "Eram/Core/Renderer/Shader.h"
#include "Eram/Core/Renderer/RenderCommand.h"
#include "Eram/Core/Renderer/Primitives.h"

namespace Eram {

	class Renderer
	{
	public:
		static void BeginScene(Camera& camera);
		static void EndScene();

		static void Submit(int primitive, const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount);
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};

}