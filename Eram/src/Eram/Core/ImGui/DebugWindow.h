#include "erpch.h"

#include <imgui.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Eram/Core/Layer.h"

#include "Eram/Scope/VideoMap.h"

namespace Eram {

	class DebugWindow : public Layer
	{
	public:
		DebugWindow();
		virtual void OnImGuiRender() override;

		const glm::vec2 GetCameraPosition() const { return m_CameraPosition; }

		void SetVideoMaps(std::vector<std::shared_ptr<VideoMap>>* videoMaps) { m_VideoMaps = videoMaps; }
	private:
		glm::vec2 m_CameraPosition;

		std::vector<std::shared_ptr<VideoMap>>* m_VideoMaps;
	};

}
