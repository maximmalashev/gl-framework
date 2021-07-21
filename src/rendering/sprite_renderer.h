#pragma once

#include "sprite.h"
#include "../scene/orthographic_camera.h"

namespace gl
{
	class SpriteRenderer
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Setup(const OrthographicCamera& camera);
		void Flush();
		void Finish();

		void Draw(const Sprite& sprite);
	};
}