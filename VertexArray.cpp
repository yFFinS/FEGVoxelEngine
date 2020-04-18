#include "VertexArray.h"
#include "SafetyCheck.h"

namespace feg {

	VertexArray::VertexArray()
	{
		Generate();
	}

	VertexArray::~VertexArray()
	{
		Dispose();
	}

	void VertexArray::Generate()
	{
		Dispose();
		GLCALL(glGenVertexArrays(1, &_id));
	}

	void VertexArray::Bind() const
	{
		ASSERT(_id != 0);
		GLCALL(glBindVertexArray(_id));
	}

	void VertexArray::AddBuffer(const VertexBuffer& vbo, const VertexBufferLayout& vbl)
	{
		Bind();
		vbo.Bind();
		const auto elems = vbl.getElements();
		unsigned char offset = 0;
		for (unsigned char i = 0; i < elems.size(); i++)
		{
			const auto& elem = elems[i];
			GLCALL(glEnableVertexAttribArray(i));
			GLCALL(glVertexAttribPointer(i, elem.count, elem.type, elem.normalized, vbl.getStride(), (const void*)offset));
			offset += elem.count * VertexBufferElement::GetTypeSize(elem.type);
		}
		vbo.Unbind();
		Unbind();
	}

	void VertexArray::Unbind() const
	{
		GLCALL(glBindVertexArray(0));
	}

	void VertexArray::Dispose()
	{
		if (_id != 0)
			GLCALL(glDeleteVertexArrays(1, &_id));
	}

}