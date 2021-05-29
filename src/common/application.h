#pragma once

#include "../window/window.h"

namespace gl
{
	class Application
	{
	public:
		Application(Window* window);
		~Application();

		void Start();
		virtual void Update() = 0;
	protected:
		Window* m_window;
	};
}