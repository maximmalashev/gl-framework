#include "window.h"

#include <iostream>

namespace gl 
{
	Window::Window(int width, int height, std::string title)
	{
		if (!glfwInit())
		{
			std::cout << "ERROR: glfw could not initialize." << std::endl;
			std::exit(-1);
		}

		m_glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!m_glfwWindow)
		{
			std::cout << "ERROR: glfw window could not initialize." << std::endl;
			glfwTerminate();
			std::exit(-1);
		}

		glfwMakeContextCurrent(m_glfwWindow);
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

