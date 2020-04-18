#include "Vector4.h"

namespace feg {

	Vector4::Vector4() noexcept : x(0), y(0), z(0), w(0)
	{
	}

	Vector4::Vector4(const float& x, const float& y, const float& z, const float& w) noexcept : x(x), y(y), z(z), w(w)
	{
	}

	Vector4::Vector4(const Vector3& xyz, const float& w) noexcept : x(xyz.x), y(xyz.y), z(xyz.z), w(w)
	{
	}

	Vector4::Vector4(const float& x, const Vector3& yzw) noexcept : x(x), y(yzw.x), z(yzw.y), w(yzw.z)
	{
	}

	Vector4::Vector4(const float& x, const Vector2& yz, const float& w) noexcept : x(x), y(yz.x), z(yz.y), w(w)
	{
	}

	Vector4::Vector4(const float& t) noexcept : x(t), y(t), z(t), w(t)
	{
	}

	Vector4::Vector4(const Vector2& xy, const Vector2& zw) noexcept : x(xy.x), y(xy.y), z(zw.x), w(zw.y)
	{
	}

	Vector4::Vector4(const Vector2& xy) noexcept : x(xy.x), y(xy.y), z(0), w(0)
	{
	}

	Vector4::Vector4(const Vector3& xyz) noexcept : x(xyz.x), y(xyz.y), z(xyz.z), w(0)
	{
	}

	Vector4::Vector4(const Vector2& xy, const float& z, const float& w) noexcept : x(xy.x), y(xy.y), z(z), w(w)
	{
	}

	Vector4 operator-(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		return lhs + (-rhs);
	}
	Vector4 operator*(const Vector4& lhs, const float& rhs) noexcept
	{
		Vector4 vec(lhs);
		vec *= rhs;
		return vec;
	}
	Vector4 operator-(const Vector4& lhs) noexcept
	{
		return Vector4(-lhs.x, -lhs.y, -lhs.z, -lhs.w);
	}
	Vector4 operator+(const Vector4& lhs, const Vector4& rhs) noexcept
	{
		Vector4 vec(lhs);
		vec += rhs;
		return vec;
	}
	Vector4 operator*(const float& lhs, const Vector4& rhs) noexcept
	{
		return rhs * lhs;
	}
	Vector4 zero() noexcept
	{
		return Vector4(0);
	}
	Vector4 one() noexcept
	{
		return Vector4(1);
	}
	Vector4 operator/(const Vector4& lhs, const float& rhs)
	{
		Vector4 vec(lhs);
		vec /= rhs;
		return vec;
	}
}