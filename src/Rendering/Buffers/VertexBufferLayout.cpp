
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

	VertexBufferElement::VertexBufferElement(const ShaderDataType& dataType, const std::string& name, const bool& normalized) noexcept :
		size(GetDataTypeSize(dataType)), type(dataType), name(name), normalized(normalized), offset(0)
	{
	}
	
	uint8_t VertexBufferElement::GetComponentCount() const
	{
		switch (type)
		{
		case ShaderDataType::Float:   return 1;
		case ShaderDataType::Float2:  return 2;
		case ShaderDataType::Float3:  return 3;
		case ShaderDataType::Float4:  return 4;
		case ShaderDataType::Mat4:    return 16;
		case ShaderDataType::Int:     return 1;
		case ShaderDataType::Bool:    return 1;
		}

		ASSERT_MSG(false, "Invalide data type");
		return 0;
	}

}