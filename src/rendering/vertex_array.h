#pragma once

#include "buffer.h"

namespace gl
{
	class VertexArray
	{
	public:
		VertexArray(std::shared_ptr<VertexBuffer> vbo, std::shared_ptr<IndexBuffer> ibo);
		~VertexArray();

		void Bind();
		static void Unbind();

		inline const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const { return m_vbo; }
		inline const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_ibo; }

	private:
		u32 m_id;

		std::shared_ptr<VertexBuffer> m_vbo;
		std::shared_ptr<IndexBuffer> m_ibo;
	};
}