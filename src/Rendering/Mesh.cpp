

namespace feg {

	Mesh::~Mesh()
	{
		Dispose();
	}

	Mesh::Mesh() : _vao(new VertexArray())
	{
		_vbo = VertexBuffer::Create(0, 0);
		_ibo = IndexBuffer::Create(0, 0);
		const VertexBufferLayout& vbl = { {ShaderDataType::Float3, "u_Position", false} };
		_vbo->SetLayout(vbl);
		_vao->AddBuffer(_vbo);
		_vao->SetIndexBuffer(_ibo);
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
	const std::shared_ptr<VertexArray> Mesh::GetVao() const noexcept
	{
		return _vao;
	}
}
