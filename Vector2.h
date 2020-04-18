#pragma once
#ifndef Vector2_H
#define Vector2_H
#include <cmath>
#include "SafetyCheck.h"
namespace feg {
	struct Vector2
	{
	public:
		Vector2() noexcept;
		Vector2(const float& x, const float& y) noexcept;

		inline float magnitude() const noexcept {
			return sqrtf(sqrMagnitude());
		}
		inline float sqrMagnitude() const noexcept {
			return x * x + y * y;
		}

		inline Vector2& operator+=(const Vector2& rhs) noexcept {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}
		inline Vector2& operator-=(const Vector2& rhs) noexcept {
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}
		inline Vector2& operator*=(const float& rhs) noexcept {
			x *= rhs;
			y *= rhs;
			return *this;
		}
		inline Vector2& operator/=(const float& rhs) {
			ASSERT(rhs != 0);
			x /= rhs;
			y /= rhs;
			return *this;
		}
		inline Vector2& DivideValues(const Vector2& rhs) {
			ASSERT(rhs.x != 0 && rhs.y != 0);
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}
		inline Vector2& MultipleValues(const Vector2& rhs) noexcept {
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

	public:
		float x;
		float y;

		inline static Vector2 zero() noexcept {
			return Vector2(0, 0);
		}
		inline static Vector2 one() noexcept {
			return Vector2(1, 1);
		}
	};

	extern inline Vector2 operator/(const Vector2& lhs, const float& rhs);
	extern inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs) noexcept;
	extern inline Vector2 operator*(const Vector2& lhs, const float& rhs) noexcept;
	extern inline Vector2 operator*(const float& lhs, const Vector2& rhs) noexcept;
	extern inline Vector2 operator-(const Vector2& lhs) noexcept;
	extern inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs) noexcept;
}
#endif // !Vector2_H

