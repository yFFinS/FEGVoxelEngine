#include "IndexBuffer.h"
#include "SafetyCheck.h"

namespace feg {

	IndexBuffer::IndexBuffer() : _count(0)
	{
	}

	IndexBuffer::~IndexBuffer()
	{
		Dispose();
	}

	void IndexBuffer::Bind() const
	{
		ASSERT(_id != 0);
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _id));
	}

	void IndexBuffer::Unbind() const
	{
#ifndef NDEBUG
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
#endif // !NDEBUG
	}

	void IndexBuffer::Generate()
	{
		Dispose();
		GLCALL(glGenBuffers(1, &_id));
	}

	void IndexBuffer::SetIndices(const uint16_t& count, const uint16_t* indices)
	{
		Bind();
		_count = count;
		GLCALL(glBufferSubData(GL_ARRAY_BUFFER, 0, count * sizeof(uint16_t), indices));
		Unbind();
	}

	void IndexBuffer::Dispose()
	{
		Unbind();
		if (_id != 0)
			GLCALL(glDeleteBuffers(1, &_id));
	}
	const uint16_t IndexBuffer::GetCount() const noexcept
	{
		return _count;
	}

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(const uint16_t& count, const uint16_t* indices)
	{
		std::shared_ptr<IndexBuffer> buf(new IndexBuffer());
		buf->Generate();
		buf->Bind();
		GLCALL(glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint16_t), indices, GL_STATIC_DRAW));
		buf->Unbind();
		return buf;
	}
}