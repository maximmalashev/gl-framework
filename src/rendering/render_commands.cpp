#include "pch.h"

#include "render_commands.h"

namespace gl
{
	namespace RenderCommands
	{
		void Clear(f32 red, f32 green, f32 blue)
		{
			glClearColor(red, green, blue, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void DrawTriangles(std::shared_ptr<VertexArray> vao, std::shared_ptr<Shader> shader)
		{
			shader->Use();
			vao->Bind();

			glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
		}
	}
}

