#include "IndexBuffer.h"
#include "SafetyCheck.h"

namespace feg {

	IndexBuffer::IndexBuffer() : _count(0), _maxIndexCount(0)
	{
	}

	IndexBuffer::~IndexBuffer()
	{
		Dispose();
	}

	void IndexBuffer::Bind() const
	{
		ASSERT_MSG(_id != 0, "Index Buffer not created.");
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id));
	}

	void IndexBuffer::Unbind() const
	{
#ifndef NDEBUG
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
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
		if (_maxIndexCount >= count) {
			GLCALL(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, count * sizeof(uint16_t), indices));
		}
		else {
			GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint16_t), indices, GL_STATIC_DRAW));
			_maxIndexCount = count;
		}
		_count = count;
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
		buf->_maxIndexCount = count;
		GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint16_t), indices, GL_STATIC_DRAW));
		buf->Unbind();
		return buf;
	}
}