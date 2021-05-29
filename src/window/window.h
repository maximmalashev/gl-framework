#pragma once

#include <GLFW/glfw3.h>

#include <string>

namespace gl 
{	
	class Window
	{
	public:
		Window(int width, int height, std::string title);
		~Window();

		inline bool ShouldClose() const { return glfwWindowShouldClose(m_glfwWindow); }
		void SwapBuffers();
		void PollEvents();
	private:
		GLFWwindow* m_glfwWindow;
	};
}
