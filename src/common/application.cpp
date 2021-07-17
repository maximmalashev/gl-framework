#include "pch.h"

#include "application.h"

#include "../rendering/buffer.h"
#include "../rendering/vertex_array.h"
#include "../rendering/shader.h"

#include <direct.h>
#include <limits.h>

namespace gl
{
    Application::Application() = default;
    Application::~Application() = default;

	void Application::Initialize(WindowSettings& windowSettings)
	{
        m_window = std::make_shared<Window>(windowSettings);
        
        std::shared_ptr<Shader> shader = Shader::FromFile("../OpenGL-Engine/res/shaders/sprite.shader");

        float vertices[] = {
             0.5f,  0.5f, 0.0f,  
             0.5f, -0.5f, 0.0f,  
            -0.5f, -0.5f, 0.0f,  
            -0.5f,  0.5f, 0.0f    
        };
        unsigned int indices[] = { 
            0, 1, 3,  
            1, 2, 3   
        };

        std::vector<int> layout;
        layout.push_back(3);

        std::shared_ptr<VertexBuffer> vbo = std::make_shared<VertexBuffer>(12, sizeof(vertices), vertices, layout);
        std::shared_ptr<IndexBuffer> ibo = std::make_shared<IndexBuffer>(6, indices);

        std::shared_ptr<VertexArray> vao = std::make_shared<VertexArray>(vbo, ibo);

        vao->Bind();

		while (!m_window->ShouldClose())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            shader->Use();
            glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

			m_window->SwapBuffers();
			m_window->PollEvents();
		}

		m_window->~Window();
	}
}

