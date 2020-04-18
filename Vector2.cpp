#include "Vector2.h"

namespace feg {

	Vector2::Vector2() noexcept : x(0), y(0)
	{
	}

	Vector2::Vector2(const float& x, const float& y) noexcept : x(x), y(y)
	{
	}

	Vector2 operator-(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		return lhs + (-rhs);
	}
	Vector2 operator*(const Vector2& lhs, const float& rhs) noexcept
	{
		Vector2 vec(lhs);
		vec *= rhs;
		return vec;
	}
	Vector2 operator-(const Vector2& lhs) noexcept
	{
		return Vector2(-lhs.x, -lhs.y);
	}
	Vector2 operator+(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		Vector2 vec(lhs);
		vec += rhs;
		return vec;
	}
	Vector2 operator*(const float& lhs, const Vector2& rhs) noexcept
	{
		return rhs * lhs;
	}
	Vector2 operator/(const Vector2& lhs, const float& rhs)
	{
		Vector2 vec(lhs);
		vec /= rhs;
		return vec;
	}
}