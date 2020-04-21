#pragma once
#ifndef BASE_BUFFER_H
#define BASE_BUFFER_H

namespace feg {
	class BaseBuffer
	{
	protected:
		BaseBuffer() : _id(0) {};
		virtual ~BaseBuffer() {};
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void Dispose() = 0;

	protected:
		unsigned int _id;
	public:
		inline unsigned int GetId() const noexcept {
			return _id;
		}
	};

}

#endif // !BASE_BUFFER_H


