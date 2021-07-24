#include "pch.h"
#include "transform.h"

namespace gl
{
	Transform::Transform()
		: m_position(glm::vec3(0.0f, 0.0f, 0.0f)), 
		  m_rotation(glm::vec3(0.0f, 0.0f, 0.0f)), 
		  m_scale(glm::vec3(1.0f, 1.0f, 1.0f)) 
	{ 
		UpdateTransformationMatrix();
	}

	Transform::~Transform() = default;

	void Transform::UpdateTransformationMatrix()
	{
		glm::mat4 transformation = glm::mat4(1.0f);

		transformation = glm::translate(transformation, m_position);
		transformation = glm::rotate(transformation, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		transformation = glm::rotate(transformation, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		transformation = glm::rotate(transformation, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		transformation = glm::scale(transformation, m_scale);

		m_transformationMatrix = transformation;
	}
}
