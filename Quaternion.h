#pragma once
#ifndef QUATERNION_H
#define QUATERNION_H
#include "Vector4.h"
namespace feg {

	struct Quaternion
	{
	public:
		Quaternion() noexcept;
		Quaternion(const float& x, const float& y, const float& z, const float& w) noexcept;
		Quaternion(const Vector4& vector4);

	public:
		float x;
		float y;
		float z;
		float w;
	};
}


#endif // !QUATERNION_H
