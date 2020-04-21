#pragma once
#ifndef QUATERNION_H
#define QUATERNION_H
namespace feg {

	struct Quaternion
	{
	public:
		Quaternion() noexcept;
		Quaternion(const float& x, const float& y, const float& z, const float& w) noexcept;
		Quaternion(const Vector4& vector4) noexcept;

		float SqrMagnitude() const noexcept;
		float Magnitude() const noexcept;
		Quaternion& Conjugate() noexcept;
		Quaternion& Inverse() noexcept;
		Quaternion& Normalize() noexcept;

		Quaternion Conjugated() const noexcept;
		Quaternion Inversed() const noexcept;
		Quaternion Normalized() const noexcept;

		Quaternion& operator+=(const Quaternion& rhs) noexcept;
		Quaternion& operator-=(const Quaternion& rhs) noexcept;
		Quaternion& operator*=(const Quaternion& rhs) noexcept;
		Quaternion& operator*=(const float& rhs) noexcept;

		friend Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs) noexcept;
		friend Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs) noexcept;
		friend Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs) noexcept;
		friend Quaternion operator*(const Quaternion& lhs, const float& rhs) noexcept;

	public:
		float w;
		float x;
		float y;
		float z;

		static Quaternion identity() noexcept;
	};
}


#endif // !QUATERNION_H
