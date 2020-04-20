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
		if (_indexBuffer != nullptr)
			_indexBuffer->Bind();
		ASSERT_MSG(_id != 0, "Vertex Array not created.");
		GLCALL(glBindVertexArray(_id));
	}

	void VertexArray::AddBuffer(const std::shared_ptr<VertexBuffer>& vbo)
	{
		Bind();
		vbo->Bind();
		for (auto elems = vbo->GetLayout().cbegin(); elems != vbo->GetLayout().cend(); elems++)
		{
			const auto& elem = *elems;
			GLCALL(glEnableVertexAttribArray(_vertexBufferIndex));
			GLCALL(glVertexAttribPointer(_vertexBufferIndex, elem.GetComponentCount(), GetDataGLType(elem.type), elem.normalized ? GL_TRUE : GL_FALSE,
				vbo->GetLayout().GetStride(), (const void*)(elem.offset)));
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
		Bind();
		ibo->Bind();
		_indexBuffer = ibo;
		Unbind();
	}

	const std::shared_ptr<IndexBuffer> VertexArray::GetIndexBuffer() const noexcept
	{
		return _indexBuffer;
	}

}