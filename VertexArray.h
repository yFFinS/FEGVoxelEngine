#pragma once
#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H
#include "BaseBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <GL/gl3w.h>

namespace feg {
	class VertexArray :
		public BaseBuffer
	{
	public:
		VertexArray();
		~VertexArray() override;
		void Generate() override;
		void Bind() const override;
		void AddBuffer(const VertexBuffer& vbo, const VertexBufferLayout& vbl);
		void Unbind() const override;
		void Dispose() override;
	};

}
#endif // !VERTEX_ARRAY_H
