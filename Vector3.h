#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H
#include "Vector2.h"
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

		inline float magnitude() const noexcept {
			return sqrtf(sqrMagnitude());
		}
		inline float sqrMagnitude() const noexcept {
			return x * x + y * y + z * z;
		}

		inline Vector3& operator+=(const Vector3& rhs) noexcept {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}
		inline Vector3& operator-=(const Vector3& rhs) noexcept {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}
		inline Vector3& operator*=(const float& rhs) noexcept {
			x *= rhs;
			y *= rhs;
			z *= rhs;
			return *this;
		}
		inline Vector3& operator/=(const float& rhs) {
			ASSERT(rhs != 0);
			x /= rhs;
			y /= rhs;
			z /= rhs;
			return *this;
		}
		inline Vector3& DivideValues(const Vector3& rhs) {
			ASSERT(rhs.x != 0 && rhs.y != 0 && rhs.z != 0);
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}
		inline Vector3& MultipleValues(const Vector3& rhs) noexcept {
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

	public:
		float x;
		float y;
		float z;

		inline Vector2 xy() const noexcept {
			return Vector2(x, y);
		}
		inline Vector2 yx() const noexcept {
			return Vector2(y, x);
		}
		inline Vector2 xz() const noexcept {
			return Vector2(x, z);
		}
		inline Vector2 zx() const noexcept {
			return Vector2(z, x);
		}
		inline Vector2 yz() const noexcept {
			return Vector2(y, z);
		}
		inline Vector2 zy() const noexcept {
			return Vector2(z, y);
		}
		inline Vector2 xx() const noexcept {
			return Vector2(x, x);
		}
		inline Vector2 yy() const noexcept {
			return Vector2(y, y);
		}
		inline Vector2 zz() const noexcept {
			return Vector2(z, z);
		}

		inline static Vector3 zero() noexcept {
			return Vector3(0, 0, 0);
		}
		inline static Vector3 one() noexcept {
			return Vector3(1, 1, 1);
		}
		inline static Vector3 forward() noexcept {
			return Vector3(0, 0, 1);
		}
		inline static Vector3 up() noexcept {
			return Vector3(0, 1, 0);
		}
		inline static Vector3 right() noexcept {
			return Vector3(1, 0, 0);
		}
	};

	extern inline Vector3 operator/(const Vector3& lhs, const float& rhs);
	extern inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept;
	extern inline Vector3 operator*(const Vector3& lhs, const float& rhs) noexcept;
	extern inline Vector3 operator*(const float& lhs, const Vector3& rhs) noexcept;
	extern inline Vector3 operator-(const Vector3& lhs) noexcept;
	extern inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept;
}
#endif // !VECTOR3_H

