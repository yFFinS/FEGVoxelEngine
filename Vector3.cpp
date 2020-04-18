#include "Vector3.h"

namespace feg {

	Vector3::Vector3() noexcept : x(0), y(0), z(0)
	{
	}

	Vector3::Vector3(const float& x, const float& y, const float& z) noexcept : x(x), y(y), z(z)
	{
	}

	Vector3::Vector3(const Vector2& xy, const float& z) noexcept : x(xy.x), y(xy.y), z(z)
	{
	}

	Vector3::Vector3(const float& x, const Vector2& yz) noexcept : x(x), y(yz.x), z(yz.y)
	{
	}

	Vector3::Vector3(const float& t) noexcept : x(t), y(t), z(t)
	{
	}

	Vector3::Vector3(const Vector2& xy) noexcept : x(xy.x), y(xy.y), z(0)
	{
	}

	Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		return lhs + (-rhs);
	}
	Vector3 operator*(const Vector3& lhs, const float& rhs) noexcept
	{
		Vector3 vec(lhs);
		vec *= rhs;
		return vec;
	}
	Vector3 operator-(const Vector3& lhs) noexcept
	{
		return Vector3(-lhs.x, -lhs.y, -lhs.z);
	}
	Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		Vector3 vec(lhs);
		vec += rhs;
		return vec;
	}
	Vector3 operator*(const float& lhs, const Vector3& rhs) noexcept
	{
		return rhs * lhs;
	}
	Vector3 operator/(const Vector3& lhs, const float& rhs)
	{
		Vector3 vec(lhs);
		vec /= rhs;
		return vec;
	}
}