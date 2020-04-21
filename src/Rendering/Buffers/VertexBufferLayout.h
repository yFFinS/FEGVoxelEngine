#pragma once
#ifndef VERTEX_BUFFER_LAYOUT_H
#define VERTEX_BUFFER_LAYOUT_H
namespace feg {

	enum class ShaderDataType {
		None = 0, Float, Float2, Float3, Float4, Mat4, Int, Bool
	};

	static unsigned int GetDataTypeSize(ShaderDataType type) {
		switch (type) {
		case ShaderDataType::None: return 0;
		case ShaderDataType::Float: return 4;
		case ShaderDataType::Float2: return 8;
		case ShaderDataType::Float3: return 12;
		case ShaderDataType::Float4: return 16;
		case ShaderDataType::Mat4: return 64;
		case ShaderDataType::Int: return 4;
		case ShaderDataType::Bool: return 1;
		}
		ASSERT_MSG(false, "Invalid data type");
		return 0;
	}

	static GLenum GetDataGLType(ShaderDataType type) {
		switch (type) {
		case ShaderDataType::Float: return GL_FLOAT;
		case ShaderDataType::Float2: return GL_FLOAT;
		case ShaderDataType::Float3: return GL_FLOAT;
		case ShaderDataType::Float4: return GL_FLOAT;
		case ShaderDataType::Mat4: return GL_FLOAT;
		case ShaderDataType::Int: return GL_INT;
		case ShaderDataType::Bool: return GL_BOOL;
		}
		ASSERT_MSG(false, "Invalid data type");
		return 0;
	}

	struct VertexBufferElement {
		std::string name;
		uint16_t size;
		ShaderDataType type;
		uint16_t offset;
		bool normalized;

		VertexBufferElement(const ShaderDataType& dataType, const std::string& name, const bool& normalized = false) noexcept;
		uint8_t GetComponentCount() const;
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout() = delete;
		VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements) noexcept;
		~VertexBufferLayout() noexcept;
		void Clear() noexcept;

	private:
		std::vector<VertexBufferElement> _data;
		unsigned int _stride;

	public:
		inline unsigned int GetStride() const noexcept {
			return _stride;
		}

		inline std::vector<VertexBufferElement>::iterator begin() noexcept {
			return _data.begin();
		}
		inline std::vector<VertexBufferElement>::iterator end() noexcept {
			return _data.end();
		}
		inline std::vector<VertexBufferElement>::const_iterator cbegin() const noexcept {
			return _data.cbegin();
		}
		inline std::vector<VertexBufferElement>::const_iterator cend() const noexcept {
			return _data.cend();
		}
	};
}
#endif // !VERTEX_BUFFER_LAYOUT_H
