#include "Math.h"
#include <cmath>
#include "SafetyCheck.h"

namespace feg {

	float Math::Sin(const float& radians)
	{
		return std::sinf(radians);
	}

	float Math::Cos(const float& radians)
	{
		return std::cosf(radians);
	}

	float Math::Lerp(const float& a, const float& b, const float& t) noexcept
	{
		return a + (b - a) * Clamp01(t);
	}

	int Math::Round(const float& value) noexcept
	{
		return static_cast<int>(std::round(value));
	}

	float Math::Tan(const float& radians)
	{
		ASSERT(radians != 0.5f && radians != 1.5f);
		return std::tanf(radians);
	}

	float Math::Ctn(const float& radians)
	{
		ASSERT(radians != 1 && radians != 2 && radians != 0.5f && radians != 1.5f);
		return 1 / std::tanf(radians);
	}

	float Math::Clamp01(const float& value) noexcept
	{
		return Clamp(value, 0, 1);
	}

	float Math::Clamp(const float& value, const float& min, const float& max) noexcept
	{
		return Min(Max(min, value), max);
	}

	float Math::Min(const float& a, const float& b) noexcept
	{
		return a < b ? a : b;
	}

	float Math::Max(const float& a, const float& b) noexcept
	{
		return a > b ? a : b;
	}

	float Math::Sqrt(const float& value)
	{
		ASSERT(value >= 0);
		return std::sqrtf(value);
	}

	float Math::Pow(const float& value, const float& power)
	{
		ASSERT(value >= 0 && (value != 0 || power != 0));
		return std::powf(value, power);
	}

}