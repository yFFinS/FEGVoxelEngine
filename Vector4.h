#pragma once
#ifndef VECTOR4_H
#define VECTOR4_H
#include "Vector3.h"
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
		Vector4(const Vector2& xy) noexcept;
		Vector4(const Vector3& xyz) noexcept;

		inline float magnitude() const noexcept {
			return sqrtf(sqrMagnitude());
		}
		inline float sqrMagnitude() const noexcept {
			return x * x + y * y + z * z + w * w;
		}

		inline Vector4& operator+=(const Vector4& rhs) noexcept {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			w += rhs.w;
			return *this;
		}
		inline Vector4& operator-=(const Vector4& rhs) noexcept {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			w -= rhs.w;
			return *this;
		}
		inline Vector4& operator*=(const float& rhs) noexcept {
			x *= rhs;
			y *= rhs;
			z *= rhs;
			w *= rhs;
			return *this;
		}
		inline Vector4& operator/=(const float& rhs) {
			ASSERT(rhs != 0);
			x /= rhs;
			y /= rhs;
			z /= rhs;
			w /= rhs;
			return *this;
		}
		inline Vector4& DivideValues(const Vector4& rhs) {
			ASSERT(rhs.x != 0 && rhs.y != 0 && rhs.z != 0 && rhs.w != 0)
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			w /= rhs.w;
			return *this;
		}
		inline Vector4& MultipleValues(const Vector4& rhs) noexcept {
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			w *= rhs.w;
			return *this;
		}

	public:
		float x;
		float y;
		float z;
		float w;

		
	};

	inline static Vector4 zero() noexcept;
	inline static Vector4 one() noexcept;
	extern inline Vector4 operator/(const Vector4& lhs, const float& rhs);
	extern inline Vector4 operator-(const Vector4& lhs, const Vector4& rhs) noexcept;
	extern inline Vector4 operator*(const Vector4& lhs, const float& rhs) noexcept;
	extern inline Vector4 operator*(const float& lhs, const Vector4& rhs) noexcept;
	extern inline Vector4 operator-(const Vector4& lhs) noexcept;
	extern inline Vector4 operator+(const Vector4& lhs, const Vector4& rhs) noexcept;
}
#endif // !Vector4_H

