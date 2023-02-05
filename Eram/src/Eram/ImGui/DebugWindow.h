#include "erpch.h"

#include <imgui.h>
#include <glad/glad.h>
#include "Eram/Layer.h"

namespace Eram {

	class DebugWindow : public Layer
	{
	public:
		virtual void OnImGuiRender() override;

		inline GLfloat GetBackroundRed() const { return m_BackroundRed; }
		inline GLfloat GetBackroundGreen() const { return m_BackroundGreen; }
		inline GLfloat GetBackroundBlue() const { return m_BackroundBlue; }
		inline GLfloat GetBackroundAlpha() const { return m_BackroundAlpha; }
	private:
		GLfloat m_BackroundRed = 0, m_BackroundGreen = 0, m_BackroundBlue = 0, m_BackroundAlpha = 0;
	};

}
