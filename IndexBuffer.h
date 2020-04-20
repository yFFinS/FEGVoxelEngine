#pragma once
#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H
#include "BaseBuffer.h"
#include <stdint.h>
#include <memory>
namespace feg {

	class IndexBuffer :
		public BaseBuffer
	{
	private:
		uint16_t _count;
		uint16_t _maxIndexCount;

	public:
		IndexBuffer();
		~IndexBuffer() override;
		void Bind() const override;
		void Unbind() const override;
		void Generate();
		void SetIndices(const uint16_t& count, const uint16_t* indices);
		void Dispose() override;
		const uint16_t GetCount() const noexcept;

	public:
		static std::shared_ptr<IndexBuffer> Create(const uint16_t& count, const uint16_t* indices);
	};


}
#endif // !INDEX_BUFFER_H

