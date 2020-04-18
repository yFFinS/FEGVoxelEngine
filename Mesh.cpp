#include "Mesh.h"
#include "SafetyCheck.h"
#include "Application.h"
#include "Renderer.h"

namespace feg {

	Mesh::~Mesh()
	{
		Dispose();
	}

	Mesh::Mesh(const unsigned char& layer) : _vbo(), _ibo(), _layer(layer)
	{
		_vao = Renderer::Get().GetVao(_layer);
		VertexBufferLayout vbl;
		vbl.Push<float>(3);
		_vao->AddBuffer(_vbo, vbl);
	}

	void Mesh::SetVertices(const unsigned int& count, const Vector3* vertices)
	{
		_vertices.clear();
		for (unsigned int i = 0; i < count; i++)
		{
			_vertices.push_back(Vector3(vertices[i]));
		}
		_vbo.SetData(count * sizeof(Vector3), &_vertices.front());
	}

	void Mesh::SetIndices(const unsigned int& count, const unsigned int* indices)
	{
		_indices.clear();
		for (unsigned int i = 0; i < count; i++)
		{
			_indices.push_back(IndexType(indices[i]));
		}
		_ibo.SetIndices(count, &_indices.front());
	}

	void Mesh::Dispose()
	{
		_vbo.Dispose();
		_ibo.Dispose();
	}
}
