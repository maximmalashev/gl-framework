#include "pch.h"
#include "orthographic_camera.h"

namespace gl
{
	OrthographicCamera::OrthographicCamera(f32 width, f32 height, f32 near, f32 far)
		:m_width(width), m_height(height), m_near(near), m_far(far) 
	{
		m_projectionMatrix = glm::ortho(0.0f, width, 0.0f, height, near, far);
	}
	
	OrthographicCamera::~OrthographicCamera() = default;
}


