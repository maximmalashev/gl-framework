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

		/* Translation */
		transformation = glm::translate(transformation, m_position);

		/* Rotation */
		glm::quat rotationQuaternion = glm::quat(glm::radians(m_rotation));
		glm::mat4 rotation = glm::mat4_cast(rotationQuaternion);
		transformation *= rotation;

		/* Scale */
		transformation = glm::scale(transformation, m_scale);

		m_transformationMatrix = transformation;
	}
}
