#pragma once

#include "Eram/Core/Layer.h"
#include "Eram/Core/Events/Event.h"

#include "Eram/Core/Renderer/Shader.h"
#include "Eram/Core/Renderer/Buffer.h"
#include "Eram/Core/Renderer/VertexArray.h"
#include "Eram/Core/Renderer/Camera.h"

namespace Eram {

	class Scope : public Layer
	{
	public:
		Scope();
		virtual ~Scope() {};

		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;

	private:
		std::shared_ptr<VertexArray> m_TriangleVertexArray;
		std::shared_ptr<Shader> m_TriangleShader;

		Camera m_Camera;
	};

}