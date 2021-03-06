#pragma once

namespace gl 
{	
	struct WindowSettings
	{
		i32 width, height;
		std::string title;
		bool vSync = false;
	};

	class Window
	{
	public:
		Window(WindowSettings& settings);
		~Window();

		inline bool ShouldClose() const { return glfwWindowShouldClose(m_glfwWindow); }
		
		void SwapBuffers();
		void PollEvents();
		float GetTime();
		void SetVSync(bool value);
		void Close();

		static void KeyCallback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);
	private:
		GLFWwindow* m_glfwWindow;

	};
}
