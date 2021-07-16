#pragma once

#include <vector>
#include <memory>

#include "../window/window.h"

namespace gl
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Initialize(WindowSettings& windowSettings);
		virtual void Update() = 0;
	protected:
		std::shared_ptr<Window> m_window;
	};
}