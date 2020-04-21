#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H
namespace feg {
	struct Vector3
	{
	public:
		Vector3() noexcept;
		Vector3(const float& x, const float& y, const float& z) noexcept;
		Vector3(const Vector2& xy, const float& z) noexcept;
		Vector3(const float& x, const Vector2& yz) noexcept;
		Vector3(const float& t) noexcept;
		Vector3(const Vector2& xy) noexcept;

		float Magnitude() const noexcept;
		float SqrMagnitude() const noexcept;

		Vector3& operator+=(const Vector3& rhs) noexcept;
		Vector3& operator-=(const Vector3& rhs) noexcept;
		Vector3& operator*=(const float& rhs) noexcept;
		Vector3& operator/=(const float& rhs);
		Vector3& DivideValues(const Vector3& rhs);
		Vector3& MultipleValues(const Vector3& rhs) noexcept;

		friend Vector3 operator/(const Vector3& lhs, const float& rhs);
		friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept;
		friend Vector3 operator*(const Vector3& lhs, const float& rhs) noexcept;
		friend Vector3 operator*(const float& lhs, const Vector3& rhs) noexcept;
		friend Vector3 operator-(const Vector3& lhs) noexcept;
		friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept;

	public:
		float x;
		float y;
		float z;

		Vector2 xy() const noexcept;
		Vector2 yx() const noexcept;
		Vector2 xz() const noexcept;
		Vector2 zx() const noexcept;
		Vector2 yz() const noexcept;
		Vector2 zy() const noexcept;
		Vector2 xx() const noexcept;
		Vector2 yy() const noexcept;
		Vector2 zz() const noexcept;

		static Vector3 zero() noexcept;
		static Vector3 one() noexcept;
		static Vector3 forward() noexcept;
		static Vector3 up() noexcept;
		static Vector3 right() noexcept;
	};


}
#endif // !VECTOR3_H

