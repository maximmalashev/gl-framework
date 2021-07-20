#include "pch.h"

#include "application.h"

#include "../rendering/buffer.h"
#include "../rendering/vertex_array.h"
#include "../rendering/shader.h"
#include "../rendering/render_commands.h"

namespace gl
{
	Application::Application(WindowSettings& windowSettings)
	{
		m_window = std::make_shared<Window>(windowSettings);
	}

    Application::~Application() = default;

	void Application::Run()
	{
		while (!m_window->ShouldClose())
		{
			RenderCommands::Clear(0.0f, 0.0f, 0.0f);

			OnUpdate();
			OnRender();

			m_window->SwapBuffers();
			m_window->PollEvents();
		}

		m_window->~Window();
	}
}

