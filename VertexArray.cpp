#include "VertexArray.h"
#include "SafetyCheck.h"

namespace feg {

	VertexArray::VertexArray() : _vertexBufferIndex(0)
	{
		GLCALL(glGenVertexArrays(1, &_id));
	}

	VertexArray::~VertexArray()
	{
		Dispose();
	}

	void VertexArray::Bind() const
	{
		ASSERT(_id != 0);
		GLCALL(glBindVertexArray(_id));
		if (_indexBuffer != nullptr)
			_indexBuffer->Bind();
	}

	void VertexArray::AddBuffer(const std::shared_ptr<VertexBuffer>& vbo)
	{
		Bind();
		vbo->Bind();
		for (auto elems = vbo->GetLayout().cbegin(); elems != vbo->GetLayout().cend(); elems++)
		{
			const auto& elem = *elems;
			GLCALL(glEnableVertexAttribArray(_vertexBufferIndex));
			GLCALL(glVertexAttribPointer(_vertexBufferIndex, elem.size, GetDataGLType(elem.type), elem.normalized ? GL_TRUE : GL_FALSE,
				vbo->GetLayout().getStride(), (const void*)(elem.offset)));
			_vertexBufferIndex++;
		}
		_vertexBuffers.push_back(vbo);
		vbo->Unbind();
		Unbind();
	}

	void VertexArray::Unbind() const
	{
#ifndef NDEBUG
		if (_indexBuffer != nullptr)
			_indexBuffer->Unbind();
		GLCALL(glBindVertexArray(0));
#endif //!NDEBUG
	}

	void VertexArray::Dispose()
	{
		if (_id != 0)
			GLCALL(glDeleteVertexArrays(1, &_id));
	}

	void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ibo)
	{
		_indexBuffer = ibo;
	}

	const std::shared_ptr<IndexBuffer> VertexArray::GetIndexBuffer() const noexcept
	{
		return _indexBuffer;
	}

}