#pragma once
#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H


namespace feg {
	
	typedef GLenum das;

	class VertexBuffer :
		public BaseBuffer
	{
	private:
		VertexBufferLayout _bufferLayout;
		uint32_t _maxBufferSize;
	public:

		VertexBuffer();
		~VertexBuffer() override;
		void Bind() const override;
		void SetData(const uint32_t& size, const void* data);
		void Unbind() const override;
		void Generate();
		void Dispose() override;
		void SetLayout(const VertexBufferLayout& layout) noexcept;
		const VertexBufferLayout& GetLayout() const noexcept;
		
	public:
		static std::shared_ptr<VertexBuffer> Create(const uint32_t& size, const void* data);
	};
}

#endif // !VERTEX_BUFFER_H
