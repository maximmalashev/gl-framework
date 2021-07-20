#pragma once

#include "../window/window.h"

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
	protected:
		std::shared_ptr<Window> m_window;
	};
}