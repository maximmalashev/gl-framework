#include "../common.h"
#include "buffer.h"

#include <numeric>

namespace gl
{
	Buffer::Buffer(i32 count)
		: m_count(count) 
	{
		glGenBuffers(1, &m_id);
	}

	Buffer::~Buffer() = default;

	IndexBuffer::IndexBuffer(i32 count, u32* data)
		: Buffer(count)
	{
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(u32), data, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	}
	void IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	VertexBuffer::VertexBuffer(i32 count, i32 size, f32* data, std::vector<i32> layout)
		: Buffer(count), m_size(size), m_layout(layout)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(f32), data, GL_STATIC_DRAW);

		i32 stride = std::accumulate(layout.begin(), layout.end(), 0) * sizeof(f32);
		i32 offset = 0;

		for (i32 location = 0; location < layout.size(); location++)
		{
			glVertexAttribPointer(location, layout[location], GL_FLOAT, GL_FALSE, stride, reinterpret_cast<const void*>(offset));
			glEnableVertexAttribArray(0);

			offset += layout[location] * sizeof(f32);
		}
	}
	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}


