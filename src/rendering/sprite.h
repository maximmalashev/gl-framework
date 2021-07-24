#pragma once

#include "../scene/transform.h"

namespace gl
{
	class Sprite : public Transform 
	{
	public:
		Sprite(glm::vec4 color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		~Sprite();

		inline glm::vec4 GetColor() const { return m_color; }

		inline void SetColor(glm::vec4 color) { m_color = color; }
	private:
		glm::vec4 m_color;
	};
}