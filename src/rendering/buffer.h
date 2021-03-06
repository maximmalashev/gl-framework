#pragma once

namespace gl
{
	class Buffer
	{
	public:
		Buffer(i32 count);
		virtual ~Buffer();

		virtual void Bind() = 0;

		inline i32 GetCount() const { return m_count; }
	protected:
		u32 m_id;
		i32 m_count;
	};

	class IndexBuffer final : public Buffer
	{
	public:
		IndexBuffer(i32 count, u32* data);
		~IndexBuffer() override;

		void Bind() override;
		static void Unbind();
	private:
	};

	class VertexBuffer final : public Buffer
	{
	public:
		VertexBuffer(i32 count, i32 size, f32* data, std::vector<i32> layout);
		VertexBuffer(i32 count, i32 size, std::vector<i32> layout);
		~VertexBuffer() override;

		void Bind() override;
		static void Unbind();

		inline i32 GetSize() const { return m_size; }
		inline std::vector<i32> GetLayout() const { return m_layout; }

		void SetData(f32* data, u32 size);
	private:
		i32 m_size;
		std::vector<i32> m_layout;
	};
}
