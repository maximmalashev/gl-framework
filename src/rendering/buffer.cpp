#include "pch.h"

#include "buffer.h"

namespace gl
{
	Buffer::Buffer(i32 count)
		: m_count(count) 
	{
		glGenBuffers(1, &m_id);
	}

	Buffer::~Buffer() = default;

	IndexBuffer::IndexBuffer(i32 count, u32* data)
		: Buffer(count), m_data(data) { }

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
		: Buffer(count), m_size(size), m_layout(layout), m_data(data) { }

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


