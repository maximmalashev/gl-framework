#pragma once

namespace gl
{
	enum class ShaderType { VERTEX, FRAGMENT };

	class Shader
	{
	public:
		Shader(const char* vertexSource, const char* fragmentSource);
		~Shader();

		static std::shared_ptr<Shader> FromFile(const std::string& path);
		static std::shared_ptr<Shader> FromString(const std::string& vertexSource, const std::string& fragmentSource);

		inline u32 GetID() const { return m_id; }

		void Use();
	private:
		u32 m_id;

		static u32 Compile(const char* source, ShaderType type);
		static bool ValidateCompilation(u32 id);
		static u32 Link(u32 vertexID, u32 fragmentID);
		static bool ValidateLinking(u32 id);
	};
}