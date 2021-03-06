
namespace feg {

	Vector2::Vector2() noexcept : x(0), y(0)
	{
	}

	Vector2::Vector2(const float& x, const float& y) noexcept : x(x), y(y)
	{
	}

	Vector2 operator-(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		return Vector2(lhs) -= rhs;
	}

	Vector2 operator*(const Vector2& lhs, const float& rhs) noexcept
	{
		return Vector2(lhs) *= rhs;
	}

	Vector2 operator-(const Vector2& lhs) noexcept
	{
		return Vector2(-lhs.x, -lhs.y);
	}

	Vector2 operator+(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		return Vector2(lhs) += rhs;
	}

	Vector2 operator*(const float& lhs, const Vector2& rhs) noexcept
	{
		return rhs * lhs;
	}

	Vector2 operator/(const Vector2& lhs, const float& rhs)
	{
		return Vector2(lhs) /= rhs;
	}

	float Vector2::Magnitude() const noexcept {
		return Math::Sqrt(SqrMagnitude());
	}

	inline float Vector2::SqrMagnitude() const noexcept {
		return x * x + y * y;
	}

	inline Vector2& Vector2::operator+=(const Vector2& rhs) noexcept {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	inline Vector2& Vector2::operator-=(const Vector2& rhs) noexcept {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	inline Vector2& Vector2::operator*=(const float& rhs) noexcept {
		x *= rhs;
		y *= rhs;
		return *this;
	}
	inline Vector2& Vector2::operator/=(const float& rhs) {
		ASSERT(rhs != 0);
		x /= rhs;
		y /= rhs;
		return *this;
	}
	inline Vector2& Vector2::DivideValues(const Vector2& rhs) {
		ASSERT(rhs.x != 0 && rhs.y != 0);
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}
	inline Vector2& Vector2::MultipleValues(const Vector2& rhs) noexcept {
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}
	Vector2 Vector2::DivideValues(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		return Vector2(lhs).DivideValues(rhs);
	}
	Vector2 Vector2::MultipleValues(const Vector2& lhs, const Vector2& rhs) noexcept
	{
		return Vector2(lhs).MultipleValues(rhs);
	}
	Vector2 Vector2::zero() noexcept {
		return Vector2(0, 0);
	}
	Vector2 Vector2::one() noexcept {
		return Vector2(1, 1);
	}
	Vector2 Vector2::right() noexcept
	{
		return Vector2(1, 0);
	}
	Vector2 Vector2::up() noexcept
	{
		return Vector2(0, 1);
	}
}