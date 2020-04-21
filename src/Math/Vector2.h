#pragma once
#ifndef _Vector2_H_
#define _Vector2_H_
namespace feg {
	struct Vector2
	{
	public:
		Vector2() noexcept;
		Vector2(const float& x, const float& y) noexcept;

		float Magnitude() const noexcept;
		float SqrMagnitude() const noexcept;
		Vector2& operator+=(const Vector2& rhs) noexcept;
		Vector2& operator-=(const Vector2& rhs) noexcept;
		Vector2& operator*=(const float& rhs) noexcept;
		Vector2& operator/=(const float& rhs);
		friend Vector2 operator/(const Vector2& lhs, const float& rhs);
		friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs) noexcept;
		friend Vector2 operator*(const Vector2& lhs, const float& rhs) noexcept;
		friend Vector2 operator*(const float& lhs, const Vector2& rhs) noexcept;
		friend Vector2 operator-(const Vector2& lhs) noexcept;
		friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs) noexcept;
	public:
		Vector2& DivideValues(const Vector2& rhs);
		Vector2& MultipleValues(const Vector2& rhs) noexcept;
		static Vector2 DivideValues(const Vector2& lhs, const Vector2& rhs) noexcept;
		static Vector2 MultipleValues(const Vector2& lhs, const Vector2& rhs) noexcept;


	public:
		float x;
		float y;

		static Vector2 zero() noexcept;
		static Vector2 one() noexcept;
		static Vector2 right() noexcept;
		static Vector2 up() noexcept;
	};
}
#endif // !_Vector2_H_

