#include "pch.h"
#include "shader.h"

namespace gl
{

    Shader::Shader(const char* vertexSource, const char* fragmentSource)
    {
        u32 vertexID = Compile(vertexSource, ShaderType::VERTEX);
        u32 fragmentID = Compile(fragmentSource, ShaderType::FRAGMENT);

        m_id = Link(vertexID, fragmentID);
    }

	Shader::~Shader()
	{
        glDeleteProgram(m_id);
    }

    void Shader::Use()
    {
        glUseProgram(m_id);
    }

	void Shader::SetUniformMat4(std::string name, glm::mat4 value)
	{
        Use();
        int uniformLocation = glGetUniformLocation(m_id, name.c_str());
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
	}

    u32 Shader::Compile(const char* source, ShaderType type)
    {
        u32 id = glCreateShader(type == ShaderType::VERTEX ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
        
        glShaderSource(id, 1, &source, NULL);
        glCompileShader(id);

        if (!ValidateCompilation(id))
        {
            std::cout << "ERROR: " << (type == ShaderType::VERTEX ? "Vertex" : "Fragment") << " shader failed to compile." << std::endl;
            std::exit(-1);
        }

        return id;
    }

    bool Shader::ValidateCompilation(u32 id)
    {
        i32 success;
        char infoLog[512];

        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        
        if (!success)
        {
            glGetShaderInfoLog(id, 512, NULL, infoLog);
            std::cout << infoLog << std::endl;

            return false;
        }

        return true;
    }

    u32 Shader::Link(u32 vertexID, u32 fragmentID)
    {
        u32 id = glCreateProgram();
        glAttachShader(id, vertexID);
        glAttachShader(id, fragmentID);
        glLinkProgram(id);

        if (!ValidateLinking(id))
        {
            std::cout << "ERROR: " << "Shader program failed to link." << std::endl;
            std::exit(-1);
        }

        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);

        return id;
    }

    bool Shader::ValidateLinking(u32 id)
    {
        i32 success;
        char infoLog[512];

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(id, 512, NULL, infoLog);
            std::cout << infoLog << std::endl;

            return false;
        }

        return true;
    }

    std::shared_ptr<Shader> Shader::FromFile(const std::string& path)
    {
        std::stringstream vertex;
        std::stringstream fragment;

        std::stringstream* current = nullptr;

        std::ifstream file(path);

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                if (line.rfind("@VERTEX", 0) == 0)
                {
                    current = &vertex;
                    continue;
                }
                else if (line.rfind("@FRAGMENT", 0) == 0)
                {
                    current = &fragment;
                    continue;
                }

                if (current)
                {
                    *current << line << std::endl;
                }
            }

            file.close();
        }
        else
        {
            std::cout << "ERROR: Cannot find the file: " << path << std::endl;
            std::exit(-1);
        }

        return FromString(vertex.str(), fragment.str());
    }

    std::shared_ptr<Shader> Shader::FromString(const std::string& vertexSource, const std::string& fragmentSource)
	{
		return std::make_shared<Shader>(vertexSource.c_str(), fragmentSource.c_str());
	}
}

