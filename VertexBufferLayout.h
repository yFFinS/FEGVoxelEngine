#pragma once
#ifndef VERTEX_BUFFER_LAYOUT_H
#define VERTEX_BUFFER_LAYOUT_H
#include <GL/gl3w.h>
#include "SafetyCheck.h"
#include <vector>
namespace feg {

	struct VertexBufferElement {
		unsigned int count;
		unsigned int type;
		unsigned char normalized;

		static unsigned int GetTypeSize(unsigned int type) {
			switch (type) {
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_SHORT: return sizeof(unsigned short int);
			}
			ASSERT(false);
			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout() : _data(0), _stride(0) {}
		~VertexBufferLayout() {
			Clear();
		}
		void Clear() {
			_data.clear();
		}

		template<typename T>
		void Push(const unsigned int& count) {
			ASSERT(false);
		}

		template<>
		void Push<float>(const unsigned int& count) {
			_data.push_back({ count, GL_FLOAT, GL_FALSE });
			_stride += count * VertexBufferElement::GetTypeSize(GL_FLOAT);
		}

		template<>
		void Push<unsigned short int>(const unsigned int& count) {
			_data.push_back({ count, GL_UNSIGNED_SHORT, GL_FALSE });
			_stride += count * VertexBufferElement::GetTypeSize(GL_UNSIGNED_SHORT);
		}


	private:
		std::vector<VertexBufferElement> _data;
		unsigned int _stride;
	public:
		inline unsigned int getSize() const noexcept {
			return static_cast<unsigned int>(_data.size());
		}

		inline unsigned int getStride() const noexcept {
			return _stride;
		}

		inline std::vector<VertexBufferElement> getElements() const noexcept {
			return _data;
		}
	};
}
#endif // !VERTEX_BUFFER_LAYOUT_H
