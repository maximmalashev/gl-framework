#pragma once

namespace gl
{
	class Sprite
	{
	public:
		glm::vec3 position;
		glm::vec4 color;
	};

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