#pragma once
#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H
#include "BaseBuffer.h"
namespace feg {

	typedef unsigned short int IndexType;
	class IndexBuffer :
		public BaseBuffer
	{
	private:
		IndexType _count;

	public:
		IndexBuffer();
		IndexBuffer(const IndexType& count, const IndexType* indices);
		~IndexBuffer() override;
		void Generate() override;
		void Bind() const override;
		void Unbind() const override;
		void SetIndices(const IndexType& count, const IndexType* indices);
		void Dispose() override;
		IndexType getCount() const noexcept;
	};


}
#endif // !INDEX_BUFFER_H

