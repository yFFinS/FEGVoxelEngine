#pragma once
#ifndef VECTOR4_H
#define VECTOR4_H
namespace feg {
	struct Vector4
	{
	public:
		Vector4() noexcept;
		Vector4(const float& x, const float& y, const float& z, const float& w) noexcept;
		Vector4(const Vector3& xyz, const float& w) noexcept;
		Vector4(const float& x, const Vector3& yzw) noexcept;
		Vector4(const float& x, const Vector2& yz, const float& w) noexcept;
		Vector4(const float& t) noexcept;
		Vector4(const Vector2& xy, const Vector2& zw) noexcept;
		Vector4(const Vector2& xy) noexcept;
		Vector4(const Vector2& xy, const float& z, const float& w) noexcept;
		Vector4(const Vector3& xyz) noexcept;

		float Magnitude() const noexcept;
		float SqrMagnitude() const noexcept;

		Vector4& operator+=(const Vector4& rhs) noexcept;
		Vector4& operator-=(const Vector4& rhs) noexcept;
		Vector4& operator*=(const float& rhs) noexcept;
		Vector4& operator/=(const float& rhs);
		Vector4& DivideValues(const Vector4& rhs);
		Vector4& MultipleValues(const Vector4& rhs) noexcept;

	public:
		float x;
		float y;
		float z;
		float w;

		static Vector4 zero() noexcept;
		static Vector4 one() noexcept;
		friend Vector4 operator/(const Vector4& lhs, const float& rhs);
		friend Vector4 operator-(const Vector4& lhs, const Vector4& rhs) noexcept;
		friend Vector4 operator*(const Vector4& lhs, const float& rhs) noexcept;
		friend Vector4 operator*(const float& lhs, const Vector4& rhs) noexcept;
		friend Vector4 operator-(const Vector4& lhs) noexcept;
		friend Vector4 operator+(const Vector4& lhs, const Vector4& rhs) noexcept;
		
	};
}
#endif // !Vector4_H

