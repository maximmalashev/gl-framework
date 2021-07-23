#include "pch.h"

#include "application.h"

#include "../rendering/buffer.h"
#include "../rendering/vertex_array.h"
#include "../rendering/shader.h"
#include "../rendering/render_commands.h"
#include "../rendering/sprite_renderer.h"

namespace gl
{
	Application::Application(WindowSettings& windowSettings)
	{
		m_window = std::make_shared<Window>(windowSettings);
		m_renderer = std::make_unique<SpriteRenderer>();
	}

    Application::~Application() = default;

	void Application::Run()
	{
		float lastTime = 0;

		while (!m_window->ShouldClose())
		{
			float time = m_window->GetTime();
			float deltaTime = time - lastTime;
			lastTime = time;

			RenderCommands::Clear(0.0f, 0.0f, 0.0f);

			OnUpdate(deltaTime);
			OnRender();

			m_window->SwapBuffers();
			m_window->PollEvents();
		}

		m_window->~Window();
	}

	void Application::Stop()
	{
		m_window->Close();
	}
}

