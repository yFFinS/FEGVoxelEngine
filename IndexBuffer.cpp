#include "IndexBuffer.h"
#include "SafetyCheck.h"

namespace feg {

	IndexBuffer::IndexBuffer() : _count(0)
	{
		Generate();
	}

	IndexBuffer::IndexBuffer(const IndexType& count, const IndexType* indices) : IndexBuffer()
	{
		SetIndices(count, indices);
	}

	IndexBuffer::~IndexBuffer()
	{
		Dispose();
	}

	void IndexBuffer::Generate()
	{
		Dispose();
		GLCALL(glGenBuffers(1, &_id));
	}

	void IndexBuffer::Bind() const
	{
		ASSERT(_id != 0);
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id));
	}

	void IndexBuffer::Unbind() const
	{
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	void IndexBuffer::SetIndices(const IndexType& count, const IndexType* indices)
	{
		Bind();
		_count = count;
		GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(IndexType), indices, GL_STATIC_DRAW));
		Unbind();
	}

	void IndexBuffer::Dispose()
	{
		Unbind();
		if (_id != 0)
			GLCALL(glDeleteBuffers(1, &_id));
	}
	IndexType IndexBuffer::getCount() const noexcept
	{
		return _count;
	}
}