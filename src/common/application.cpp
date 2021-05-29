#include "application.h"

namespace gl
{
	Application::Application(Window* window) 
		: m_window(window) { }

	Application::~Application() { }

	void Application::Start()
	{
		while (!m_window->ShouldClose())
		{
			m_window->SwapBuffers();
			m_window->PollEvents();
		}

		m_window->~Window();
	}
}

