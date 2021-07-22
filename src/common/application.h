#pragma once

#include "../window/window.h"
#include "../rendering/sprite_renderer.h"

namespace gl
{
	class Application
	{
	public:
		Application(WindowSettings& windowSettings);
		virtual ~Application();

		virtual void Run();
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;
		virtual void Stop();
	protected:
		std::unique_ptr<SpriteRenderer> m_renderer;
		std::shared_ptr<Window> m_window;
	};
}