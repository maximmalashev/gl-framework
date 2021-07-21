#pragma once

#include "transform.h"

namespace gl
{
	class OrthographicCamera : public Transform
	{
	public:
		OrthographicCamera(f32 width, f32 height, f32 near, f32 far);
		~OrthographicCamera();

		inline glm::mat4 GetProjectionMatrix() const { return m_projectionMatrix; }
	private:
		f32 m_width, m_height;
		f32 m_near, m_far;

		glm::mat4 m_projectionMatrix;
	};
}