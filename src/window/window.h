#pragma once

#include "../common.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

namespace gl 
{	
	struct WindowSettings
	{
		i32 width, height;
		std::string title;
	};

	class Window
	{
	public:
		Window(WindowSettings& settings);
		~Window();

		inline bool ShouldClose() const { return glfwWindowShouldClose(m_glfwWindow); }
		void SwapBuffers();
		void PollEvents();
	private:
		GLFWwindow* m_glfwWindow;
	};
}
