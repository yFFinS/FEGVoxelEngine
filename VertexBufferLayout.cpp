#include "VertexBufferLayout.h"

namespace feg {

	VertexBufferLayout::VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements) noexcept : _data(elements), _stride(0)
	{
		uint16_t offset = 0;
		for (auto& element : _data)
		{
			element.offset = offset;
			offset += element.size;
			_stride += element.size;
		}
	}

	VertexBufferLayout::~VertexBufferLayout() noexcept
	{
		Clear();
	}

	void VertexBufferLayout::Clear() noexcept
	{
		_data.clear();
	}

	VertexBufferElement::VertexBufferElement(const ShaderDataType& dataType, const std::string& name, const bool& normalized) noexcept : size(0), type(dataType), name(name), normalized(normalized), offset(0)
	{
	}

}