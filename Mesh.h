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
		IndexBuffer _ibo;
		VertexBuffer _vbo;
		VertexArray* _vao;
		unsigned char _layer;
		std::vector<IndexType> _indices;
		std::vector<Vector3> _vertices;
	public:

		~Mesh();
		Mesh(const unsigned char& layer = 0);
		void SetVertices(const unsigned int& size, const Vector3* vertices);
		void SetIndices(const unsigned int& size, const unsigned int* indices);
		void Dispose();

	};
}

#endif // !MESH_H


