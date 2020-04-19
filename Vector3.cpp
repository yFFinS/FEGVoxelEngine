#include "Vector3.h"
#include "Math.h"

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
		return Vector3(lhs) -= rhs;
	}
	Vector3 operator*(const Vector3& lhs, const float& rhs) noexcept
	{
		return Vector3(lhs) *= rhs;
	}
	Vector3 operator-(const Vector3& lhs) noexcept
	{
		return Vector3(-lhs.x, -lhs.y, -lhs.z);
	}
	Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept
	{
		return Vector3(lhs) += rhs;
	}
	Vector3 operator*(const float& lhs, const Vector3& rhs) noexcept
	{
		return rhs * lhs;
	}
	Vector3 operator/(const Vector3& lhs, const float& rhs)
	{
		return Vector3(lhs) /= rhs;
	}
	float Vector3::Magnitude() const noexcept {
		return Math::Sqrt(SqrMagnitude());
	}
	inline float Vector3::SqrMagnitude() const noexcept {
		return x * x + y * y + z * z;
	}

	inline Vector3& Vector3::operator+=(const Vector3& rhs) noexcept {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	inline Vector3& Vector3::operator-=(const Vector3& rhs) noexcept {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	inline Vector3& Vector3::operator*=(const float& rhs) noexcept {
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}
	inline Vector3& Vector3::operator/=(const float& rhs) {
		ASSERT(rhs != 0);
		x /= rhs;
		y /= rhs;
		z /= rhs;
		return *this;
	}
	inline Vector3& Vector3::DivideValues(const Vector3& rhs) {
		ASSERT(rhs.x != 0 && rhs.y != 0 && rhs.z != 0);
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}
	inline Vector3& Vector3::MultipleValues(const Vector3& rhs) noexcept {
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}
	Vector2 Vector3::xy() const noexcept {
		return Vector2(x, y);
	}
	Vector2 Vector3::yx() const noexcept {
		return Vector2(y, x);
	}
	Vector2 Vector3::xz() const noexcept {
		return Vector2(x, z);
	}
	Vector2 Vector3::zx() const noexcept {
		return Vector2(z, x);
	}
	Vector2 Vector3::yz() const noexcept {
		return Vector2(y, z);
	}
	Vector2 Vector3::zy() const noexcept {
		return Vector2(z, y);
	}
	Vector2 Vector3::xx() const noexcept {
		return Vector2(x, x);
	}
	Vector2 Vector3::yy() const noexcept {
		return Vector2(y, y);
	}
	Vector2 Vector3::zz() const noexcept {
		return Vector2(z, z);
	}
	Vector3 Vector3::zero() noexcept
	{
		return Vector3(0);
	}
	Vector3 Vector3::one() noexcept
	{
		return Vector3(1);
	}
	Vector3 Vector3::forward() noexcept
	{
		return Vector3(0, 0, 1);
	}
	Vector3 Vector3::up() noexcept
	{
		return Vector3(0, 1, 0);
	}
	Vector3 Vector3::right() noexcept
	{
		return Vector3(1, 0, 0);
	}
}