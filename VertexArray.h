#pragma once
#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

namespace feg {
	class VertexArray :
		public BaseBuffer
	{
	public:
		VertexArray();
		~VertexArray() override;
		void Bind() const override;
		void AddBuffer(const std::shared_ptr<VertexBuffer>& vbo);
		void Unbind() const override;
		void Dispose() override;

		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ibo);
		const std::shared_ptr<IndexBuffer> GetIndexBuffer() const noexcept;

	private:
		uint32_t _vertexBufferIndex;
		std::vector<std::shared_ptr<VertexBuffer>> _vertexBuffers;
		std::shared_ptr<IndexBuffer> _indexBuffer;
	};

}
#endif // !VERTEX_ARRAY_H
