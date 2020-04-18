#pragma once
#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <array>
#include "Vector4.h"
namespace feg {

	struct Matrix4x4
	{
	private:
		std::array<float, 16> _elements;
	public:
		Matrix4x4() noexcept;
		Matrix4x4(const std::array<float, 16> elements) noexcept;
		static Matrix4x4 CreateScaleMatrix(const Vector4& scale) noexcept;
		static Matrix4x4 CreateTranslationMatrix(const Vector4& translation) noexcept;
		static Matrix4x4 CreateViewMatrix(const Vector4& forward, const Vector4& up, const Vector4& right, const Vector4& position) noexcept;
		static Matrix4x4 CreatePerspectiveProjectionMatrix(const float& width, const float& height, const float& fov, const float& zNear, const float& zFar) noexcept;
		static Matrix4x4 CreateOrthographicProjectionMatrix(const float& left, const float& right, const float& top, const float& bottom, const float& zNear, const float& zFar) noexcept;

		void SetRow(const unsigned char& row, Vector4 values);
		void SetColumn(const unsigned char& col, Vector4 values);

	public:
		inline Matrix4x4& operator+=(const Matrix4x4& rhs) noexcept {
			for (unsigned char i = 0; i < 16; i++) {
				_elements[i] += rhs._elements[i];
;			}
			return *this;
		}
		inline Matrix4x4& operator-=(const Matrix4x4& rhs) noexcept {
			for (unsigned char i = 0; i < 16; i++) {
				_elements[i] -= rhs._elements[i];
;			}
			return *this;
		}
		inline Matrix4x4& operator*=(const float& rhs) noexcept {
			for (unsigned char i = 0; i < 16; i++) {
				_elements[i] *= rhs;
			}
			return *this;
		}
		inline Matrix4x4& operator/=(const float& rhs) {
			ASSERT(rhs != 0);
			for (unsigned char i = 0; i < 16; i++) {
				_elements[i] /= rhs;
			}
			return *this;
		}
		inline Matrix4x4 operator*=(const Matrix4x4& rhs) noexcept {
			for (unsigned char i = 0; i < 16; i++)
			{
				unsigned char temp1 = i / 4 * 4;
				unsigned char temp2 = i % 4;
				_elements[i] =
					_elements[temp1] * rhs._elements[temp1]
					+ _elements[temp1 + 1] * rhs._elements[4 + temp2]
					+ _elements[temp1 + 2] * rhs._elements[8 + temp2]
					+ _elements[temp1 + 3] * rhs._elements[12 + temp2];
			}
			return *this;
		}
	};

	extern inline Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs);
	extern inline Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs);
	extern inline Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs);
	extern inline Matrix4x4 operator*(const Matrix4x4& lhs, const float& rhs);


}
#endif // !MATRIX4X4_H
