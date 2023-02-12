#pragma once

#include <glm/glm.hpp>

namespace Eram {

	class Camera
	{
	public:
		Camera(float left, float right, float bottom, float top);

		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPostion(const glm::vec3& postion)
		{ 
			m_Position = postion;
			RecalculateViewMatrix();
		}

		const float GetRotation() const { return m_Rotation; }
		void SetRotation(float rotation)
		{
			m_Rotation = rotation;
			RecalculateViewMatrix();
		}

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
	private:
		void RecalculateViewMatrix();
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position;
		float m_Rotation = 0.0f;
	};

}