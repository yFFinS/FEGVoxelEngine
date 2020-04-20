#include "VertexBuffer.h"
#include "SafetyCheck.h"

namespace feg {

	VertexBuffer::VertexBuffer() : _bufferLayout({ {ShaderDataType::None, "None", false} }), _maxBufferSize(0)
	{
	}

	VertexBuffer::~VertexBuffer()
	{
		Dispose();
	}

	void VertexBuffer::Generate()
	{
		Dispose();
		GLCALL(glGenBuffers(1, &_id));
	}

	void VertexBuffer::Bind() const
	{
		ASSERT_MSG(_id != 0, "Vertex Buffer not created.");
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, _id));
	}

	void VertexBuffer::SetData(const uint32_t& size, const void* data)
	{
		Bind();
		if (_maxBufferSize >= size) {
			GLCALL(glBufferSubData(GL_ARRAY_BUFFER, 0, size, data));
		}
		else {
			GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
			_maxBufferSize = size;
		}
		Unbind();
	}

	void VertexBuffer::Unbind() const
	{
#ifndef NDEBUG
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
#endif //!NDEBUG
	}

	void VertexBuffer::Dispose()
	{
		Unbind();
		if (_id != 0)
			GLCALL(glDeleteBuffers(1, &_id));
	}

	void VertexBuffer::SetLayout(const VertexBufferLayout& layout) noexcept
	{
		_bufferLayout = layout;
	}

	const VertexBufferLayout& VertexBuffer::GetLayout() const noexcept
	{
		return _bufferLayout;
	}

	std::shared_ptr<VertexBuffer> VertexBuffer::Create(const uint32_t& size, const void* data)
	{
		std::shared_ptr<VertexBuffer> buf(new VertexBuffer());
		buf->Generate();
		buf->Bind();
		buf->_maxBufferSize = size;
		GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		buf->Unbind();
		return buf;
	}


}