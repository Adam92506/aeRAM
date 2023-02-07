#include "erpch.h"

#include <imgui.h>
#include <glad/glad.h>
#include <glm/vec4.hpp>

#include "Eram/Core/Layer.h"

namespace Eram {

	class DebugWindow : public Layer
	{
	public:
		DebugWindow();
		virtual void OnImGuiRender() override;

		inline glm::vec4 GetBackroundColor() const { return m_BackroundColor; }
	private:
		glm::vec4 m_BackroundColor;
	};

}
