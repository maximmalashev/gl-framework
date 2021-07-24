#pragma once

namespace gl
{
	class Transform
	{
	public:
		Transform();
		~Transform();

		inline glm::vec3 GetPosition() const { return m_position; }
		inline glm::vec3 GetRotation() const { return m_rotation; }
		inline glm::vec3 GetScale() const { return m_scale; }
		inline glm::mat4 GetTransformationMatrix() const { return m_transformationMatrix; };

		inline void SetPosition(const glm::vec3& newValue) { m_position = newValue; UpdateTransformationMatrix(); }
		inline void SetRotation(const glm::vec3& newValue) { m_rotation = newValue; UpdateTransformationMatrix(); }
		inline void SetScale(const glm::vec3& newValue) { m_scale = newValue; UpdateTransformationMatrix(); }
	private:
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;

		glm::mat4 m_transformationMatrix;
		
		void UpdateTransformationMatrix();
	};
}