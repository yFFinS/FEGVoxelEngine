#pragma once
#ifndef MATH_H_
#define MATH_H_
namespace feg {

	class Math
	{
		static constexpr float PI = 3.14159265358979323846f;

		static float Sin(const float& value);
		static float Cos(const float& value);
		static float Lerp(const float& a, const float& b, const float& t) noexcept;
		static int Round(const float& value) noexcept;
		static float Tan(const float& value);
		static float Ctn(const float& value);
		static float Clamp01(const float& value) noexcept;
		static float Clamp(const float& value, const float& min, const float& max) noexcept;
		static float Min(const float& a, const float& b) noexcept;
		static float Max(const float& a, const float& b) noexcept;
	};


}
#endif // !MATH_H_
