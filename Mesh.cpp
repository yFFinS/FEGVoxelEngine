#include "Mesh.h"
#include "SafetyCheck.h"
#include "Application.h"
#include "Renderer.h"

namespace feg {

	Mesh::~Mesh()
	{
		Dispose();
	}

	Mesh::Mesh() : _vao(new VertexArray()), _vbo(new VertexBuffer()), _ibo(new IndexBuffer())
	{
		_vbo->Generate();
		_ibo->Generate();
		const VertexBufferLayout& vbl = { {ShaderDataType::Float3, "u_Position", false} };
		_vbo->SetLayout(vbl);
		_vao->AddBuffer(_vbo);
	}

	void Mesh::SetVertices(const uint16_t& count, const Vector3* vertices)
	{
		_vertices.clear();
		for (uint16_t i = 0; i < count; i++)
		{
			_vertices.push_back(Vector3(vertices[i]));
		}
		_vbo->SetData(count * sizeof(Vector3), &_vertices.front());
	}

	void Mesh::SetIndices(const uint16_t& count, const uint16_t* indices)
	{
		_indices.clear();
		for (uint16_t i = 0; i < count; i++)
		{
			_indices.push_back(uint16_t(indices[i]));
		}
		_ibo->SetIndices(count, &_indices.front());
	}

	void Mesh::Dispose()
	{
		_vbo->Dispose();
		_ibo->Dispose();
		_vao->Dispose();

	}
}
