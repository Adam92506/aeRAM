#pragma once

#include "Eram/Core/Layer.h"
#include "Eram/Core/Events/Event.h"

#include "Eram/Core/Renderer/Shader.h"
#include "Eram/Core/Renderer/Buffer.h"
#include "Eram/Core/Renderer/VertexArray.h"
#include "Eram/Core/Renderer/Camera.h"

#include "Eram/Scope/VideoMap.h"

namespace Eram {

	class Scope : public Layer
	{
	public:
		Scope();
		virtual ~Scope() {};

		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;

		std::vector<std::shared_ptr<VideoMap>>* GetVideoMaps() { return &m_VideoMaps; }

		void SetCameraPosition(glm::vec2 position) { m_Camera.SetPostion( {position, 0}); }

	private:
		std::vector<std::shared_ptr<VideoMap>> m_VideoMaps;

		Camera m_Camera;
	};

}