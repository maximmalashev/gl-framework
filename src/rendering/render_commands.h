#pragma once

#include "vertex_array.h"
#include "buffer.h"
#include "shader.h"

namespace gl
{
	namespace RenderCommands
	{
		void Clear(f32 red, f32 green, f32 blue);
		void DrawTriangles(std::shared_ptr<VertexArray> vao, std::shared_ptr<Shader> shader);
	}
}