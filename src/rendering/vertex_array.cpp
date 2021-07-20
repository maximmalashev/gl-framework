#include "pch.h"
#include "vertex_array.h"

namespace gl
{
	VertexArray::VertexArray(std::shared_ptr<VertexBuffer> vbo, std::shared_ptr<IndexBuffer> ibo)
		: m_ibo(ibo), m_vbo(vbo)
	{
		glGenVertexArrays(1, &m_id);
		Bind();

		vbo->Bind();

		auto layout = vbo->GetLayout();

		i32 stride = std::accumulate(layout.begin(), layout.end(), 0) * sizeof(f32);
		i32 offset = 0;

		for (i32 location = 0; location < layout.size(); location++)
		{
			glVertexAttribPointer(location, layout[location], GL_FLOAT, GL_FALSE, stride, reinterpret_cast<const void*>(offset));
			glEnableVertexAttribArray(0);

			offset += layout[location] * sizeof(f32);
		}

		ibo->Bind();
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_id);
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(m_id);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}
}
