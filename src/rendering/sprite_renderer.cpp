#include "pch.h"
#include "sprite_renderer.h"

#include "buffer.h"
#include "shader.h"
#include "vertex_array.h"
#include "render_commands.h"

#include "../scene/orthographic_camera.h"

namespace gl
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec4 color;
	};

	namespace RendererSettings
	{
		const u32 MAX_SPRITES = 10000;
		const u32 MAX_VERTICES = MAX_SPRITES * 4;
		const u32 MAX_INDICES = MAX_SPRITES * 6;

		constexpr u32 SPRITE_SIZE = sizeof(Vertex) * 4;

		Vertex* verticesHead;
		Vertex* verticesTail;

		u32 spriteCount = 0;

		std::shared_ptr<VertexArray> vao;
		std::shared_ptr<Shader> shader;

		glm::vec4 spriteVertices[] = {

			glm::vec4( 0.5f,  0.5f,  0.0f, 1.0f),
			glm::vec4( 0.5f, -0.5f,  0.0f, 1.0f),
			glm::vec4(-0.5f, -0.5f,  0.0f, 1.0f),
			glm::vec4(-0.5f,  0.5f,  0.0f, 1.0f)
		
		};
	}

	SpriteRenderer::SpriteRenderer()
	{
		RendererSettings::verticesHead = new Vertex[RendererSettings::MAX_VERTICES];
		RendererSettings::verticesTail = RendererSettings::verticesHead;

		std::vector<i32> vboLayout;
		vboLayout.push_back(3);
		vboLayout.push_back(4);

		u32 vboCount = RendererSettings::MAX_VERTICES * (3 + 4);

		std::shared_ptr<VertexBuffer> vbo = std::make_shared<VertexBuffer>(vboCount, vboCount * sizeof(float), vboLayout);
		
		u32* indices = new u32[RendererSettings::MAX_INDICES];
		u32 offset = 0;

		for (u32 index = 0; index < RendererSettings::MAX_INDICES; )
		{
			indices[index++] = 0 + offset;
			indices[index++] = 1 + offset;
			indices[index++] = 3 + offset;

			indices[index++] = 1 + offset;
			indices[index++] = 2 + offset;
			indices[index++] = 3 + offset;	

			offset += 4;
		}

		std::shared_ptr<IndexBuffer> ibo = std::make_shared<IndexBuffer>(RendererSettings::MAX_INDICES, indices);
		delete[] indices;

		RendererSettings::vao = std::make_shared<VertexArray>(vbo, ibo);
		RendererSettings::shader = Shader::FromFile("../OpenGL-Engine/res/shaders/sprite.shader");
	}

	SpriteRenderer::~SpriteRenderer()
	{
		delete[] RendererSettings::verticesHead;
	}

	void SpriteRenderer::Setup(const OrthographicCamera& camera) 
	{ 
		RendererSettings::shader->SetUniformMat4("uProjectionView", camera.GetTransformationMatrix() * camera.GetProjectionMatrix());
	}

	void SpriteRenderer::Flush()
	{
		RendererSettings::vao->GetVertexBuffer()->SetData(reinterpret_cast<f32*>(RendererSettings::verticesHead), RendererSettings::SPRITE_SIZE * RendererSettings::spriteCount);
		
		RenderCommands::DrawTriangles(RendererSettings::vao, RendererSettings::shader);
		
		RendererSettings::verticesTail = RendererSettings::verticesHead;
		RendererSettings::spriteCount = 0;
	}

	void SpriteRenderer::Finish()
	{
		RendererSettings::vao->GetVertexBuffer()->SetData(reinterpret_cast<f32*>(RendererSettings::verticesHead), RendererSettings::SPRITE_SIZE * RendererSettings::spriteCount);
		
		RenderCommands::DrawTriangles(RendererSettings::vao, RendererSettings::shader, RendererSettings::spriteCount * 6);
		
		RendererSettings::verticesTail = RendererSettings::verticesHead;
		RendererSettings::spriteCount = 0;
	}

	void SpriteRenderer::Draw(const Sprite& sprite)
	{
		if (RendererSettings::spriteCount >= RendererSettings::MAX_SPRITES)
			Flush();

		for (i32 vertex = 0; vertex < 4; vertex++)
		{
			RendererSettings::verticesTail->position = static_cast<glm::vec3>(sprite.GetTransformationMatrix() * RendererSettings::spriteVertices[vertex]);
			RendererSettings::verticesTail->color = sprite.GetColor();

			RendererSettings::verticesTail++;
		}
		RendererSettings::spriteCount++;

	}
}