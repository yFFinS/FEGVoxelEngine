#include "Math.h"
#include <cmath>
#include "SafetyCheck.h"

namespace feg {

	float Math::Sin(const float& value)
	{
		return std::sinf(value);
	}

	float Math::Cos(const float& value)
	{
		return std::cosf(value);
	}

	float Math::Lerp(const float& a, const float& b, const float& t) noexcept
	{
		return a + (b - a) * Clamp01(t);
	}

	int Math::Round(const float& value) noexcept
	{
		return static_cast<int>(std::round(value));
	}

	float Math::Tan(const float& value)
	{
		return std::tanf(value);
	}

	float Math::Ctn(const float& value)
	{
		return 1 / Tan(value);
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

}