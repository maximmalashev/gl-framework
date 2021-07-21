#pragma once

#include "sprite.h"

namespace gl
{
	class SpriteRenderer
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Setup();
		void Flush();
		void Finish();

		void Draw(const Sprite& sprite);
	};
}