#include "Quaternion.h"
#include "Math.h"

namespace feg {

	Quaternion::Quaternion() noexcept : Quaternion(0, 0, 0, 0)
	{
	}

	Quaternion::Quaternion(const float& x, const float& y, const float& z, const float& w) noexcept : w(w), x(x), y(y), z(z)
	{
	}

	Quaternion::Quaternion(const Vector4& vector4) noexcept : Quaternion(vector4.x, vector4.y, vector4.z, vector4.w)
	{
	}

	inline float Quaternion::SqrMagnitude() const noexcept {
		return x * x + y * y + z * z + w * w;
	}
	inline float Quaternion::Magnitude() const noexcept {
		return sqrtf(SqrMagnitude());
	}
	inline Quaternion& Quaternion::Conjugate() noexcept {
		x = -x;
		y = -y;
		z = -z;
		return *this;
	}
	inline Quaternion& Quaternion::Inverse() noexcept {
		Conjugate();
		const float& sMag = SqrMagnitude();
		if (sMag != 0) {
			x /= sMag;
			y /= sMag;
			z /= sMag;
			w /= sMag;
		}
		return *this;
	}
	inline Quaternion& Quaternion::Normalize() noexcept {
		const float& sMag = SqrMagnitude();
		if (sMag != 0) {
			const float& invMag = 1 / Math::Sqrt(sMag);
			x *= invMag;
			y *= invMag;
			z *= invMag;
			w *= invMag;
		}
		return *this;
	}

	Quaternion Quaternion::Conjugated() const noexcept
	{
		return Quaternion(*this).Conjugate();
	}

	Quaternion Quaternion::Inversed() const noexcept
	{
		return Quaternion(*this).Inverse();
	}

	Quaternion Quaternion::Normalized() const noexcept
	{
		return Quaternion(*this).Normalize();
	}

	inline Quaternion& Quaternion::operator+=(const Quaternion& rhs) noexcept
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	inline Quaternion& Quaternion::operator-=(const Quaternion& rhs) noexcept
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}

	inline Quaternion& Quaternion::operator*=(const Quaternion& rhs) noexcept
	{
		const float& tX = x, tY = y, tZ = z;
		x = w * rhs.x + tX * rhs.w + tY * rhs.z - tZ * rhs.y;
		y = w * rhs.y + tY * rhs.w + tZ * rhs.x - tX * rhs.z;
		z = w * rhs.z + tZ * rhs.w + tX * rhs.y - tY * rhs.x;
		w = w * rhs.w - tX * rhs.x - tY * rhs.y - tZ * rhs.z;
		return *this;
	}

	inline Quaternion& Quaternion::operator*=(const float& rhs) noexcept
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		w *= rhs;
		return *this;
	}

	inline Quaternion Quaternion::identity() noexcept
	{
		return Quaternion(0, 0, 0, 1);
	}
	inline Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs) noexcept
	{
		return Quaternion(lhs) += rhs;
	}
	inline Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs) noexcept
	{
		return Quaternion(lhs) -= rhs;
	}
	inline Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs) noexcept
	{
		return Quaternion(lhs) *= rhs;
	}
	inline Quaternion operator*(const Quaternion& lhs, const float& rhs) noexcept
	{
		return Quaternion(lhs) *= rhs;
	}
}
