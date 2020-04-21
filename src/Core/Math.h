#pragma once
#ifndef MATH_H_
#define MATH_H_
namespace feg {

	class Math
	{
	public:
		constexpr static float PI = 3.14159265358979323846f;

		static float Sin(const float& radians);
		static float Cos(const float& radians);
		float Lerp(const float& a, const float& b, const float& t) noexcept;
		static int Round(const float& value) noexcept;
		float Tan(const float& radians);
		static float Ctn(const float& radians);
		static float Clamp01(const float& value) noexcept;
		static float Clamp(const float& value, const float& min, const float& max) noexcept;
		static float Min(const float& a, const float& b) noexcept;
		static float Max(const float& a, const float& b) noexcept;
		static float Sqrt(const float& value);
		static float Pow(const float& value, const float& power);
	};


}
#endif // !MATH_H_
