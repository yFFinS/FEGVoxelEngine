#pragma once
#ifndef MESH_H
#define MESH_H
#include "Vector3.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include <vector>
namespace feg {
	class Mesh
	{
	private:
		std::shared_ptr<IndexBuffer> _ibo;
		std::shared_ptr<VertexBuffer> _vbo;
		std::shared_ptr<VertexArray> _vao;
		std::vector<uint16_t> _indices;
		std::vector<Vector3> _vertices;
	public:

		~Mesh();
		Mesh();
		void SetVertices(const uint16_t& size, const Vector3* vertices);
		void SetIndices(const uint16_t& size, const uint16_t* indices);
		void Dispose();

	};
}

#endif // !MESH_H


