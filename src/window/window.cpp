#include "pch.h"

#include "window.h"
#include "input.h"

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
		glfwSetKeyCallback(m_glfwWindow, KeyCallback);

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
		Input::ResetPressed();
		Input::ResetReleased();

		glfwPollEvents();
	}

	void Window::Close()
	{
		glfwSetWindowShouldClose(m_glfwWindow, GLFW_TRUE);
	}

	void Window::KeyCallback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods)
	{
		if (action == GLFW_PRESS)
		{
			Input::m_keysPressed[key] = true;
			Input::m_keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			Input::m_keysReleased[key] = true;
			Input::m_keys[key] = false;
		}
	}
}

