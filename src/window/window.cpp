#include "pch.h"

#include "window.h"

namespace gl 
{
	Window::Window(WindowSettings& settings)
	{
		if (!glfwInit())
		{
			std::cout << "ERROR: glfw could not initialize." << std::endl;
			std::exit(-1);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		m_glfwWindow = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);
		if (!m_glfwWindow)
		{
			std::cout << "ERROR: glfw window could not initialize." << std::endl;
			glfwTerminate();
			std::exit(-1);
		}

		glfwMakeContextCurrent(m_glfwWindow);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "ERROR: glew could not initialize." << std::endl;
			glfwTerminate();
			std::exit(-1);
		}

		glewExperimental = true;
	}

	Window::~Window() 
	{ 
		glfwTerminate();
	}
	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_glfwWindow);
	}
	void Window::PollEvents()
	{
		glfwPollEvents();
	}
}

