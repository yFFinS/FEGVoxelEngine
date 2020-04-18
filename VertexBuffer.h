#pragma once
#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H
#include "BaseBuffer.h"
#include "Vector3.h"
#include "VertexBufferLayout.h"

namespace feg {
	class VertexBuffer :
		public BaseBuffer
	{
	public:

		VertexBuffer();
		VertexBuffer(const unsigned int& size, const void* data);
		~VertexBuffer() override;
		void Generate() override;
		void Bind() const override;
		void SetData(const unsigned int& size, const void* data);
		void Unbind() const override;
		void Dispose() override;
	};
}

#endif // !VERTEX_BUFFER_H
