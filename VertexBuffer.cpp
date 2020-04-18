#include "VertexBuffer.h"
#include "SafetyCheck.h"

namespace feg {

	VertexBuffer::VertexBuffer()
	{
		Generate();
	}

	VertexBuffer::VertexBuffer(const unsigned int& size, const void* data) : VertexBuffer()
	{
		SetData(size, data);
	}

	VertexBuffer::~VertexBuffer()
	{
		Dispose();
	}

	void VertexBuffer::SetData(const unsigned int& size, const void* data)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		Unbind();
	}

	void VertexBuffer::Generate()
	{
		Dispose();
		glGenBuffers(1, &_id);
	}

	void VertexBuffer::Bind() const
	{
		ASSERT(_id != 0);
		glBindBuffer(GL_ARRAY_BUFFER, _id);
	}

	void VertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::Dispose()
	{
		Unbind();
		if (_id != 0)
			glDeleteBuffers(1, &_id);
	}


}