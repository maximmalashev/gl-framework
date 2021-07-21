#pragma once

namespace gl
{
	class Transform
	{
	public:
		Transform();
		~Transform();

		glm::mat4 GetMatrix() const;

		inline glm::vec3 GetPosition() const { return m_position; }
		inline glm::vec3 GetRotation() const { return m_rotation; }
		inline glm::vec3 GetScale() const { return m_scale; }

		inline void SetPosition(glm::vec3 newValue) { m_position = newValue; }
		inline void SetRotation(glm::vec3 newValue) { m_rotation = newValue; }
		inline void SetScale(glm::vec3 newValue) { m_scale = newValue; }
	protected:
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}