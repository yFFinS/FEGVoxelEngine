#pragma once
#ifndef MATRIX4X4_H
#define MATRIX4X4_H
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
		static Matrix4x4 CreateRotationMatrix(const Quaternion& rotation) noexcept;
		static Matrix4x4 CreateViewMatrix(const Vector4& forward, const Vector4& up, const Vector4& right, const Vector4& position) noexcept;
		static Matrix4x4 CreatePerspectiveProjectionMatrix(const float& width, const float& height, const float& fov, const float& zNear, const float& zFar) noexcept;
		static Matrix4x4 CreateOrthographicProjectionMatrix(const float& left, const float& right, const float& top, const float& bottom, const float& zNear, const float& zFar) noexcept;
		static Matrix4x4 CreateTRSMatrix(const Vector4& translation, const Quaternion& rotation, const Vector4& scale) noexcept;
 
		void SetRow(const unsigned char& row, Vector4 values);
		void SetColumn(const unsigned char& col, Vector4 values);
		const float* GetElementsPtr() const noexcept;

	public:
		Matrix4x4& operator+=(const Matrix4x4& rhs) noexcept;
		Matrix4x4& operator-=(const Matrix4x4& rhs) noexcept;
		Matrix4x4& operator*=(const float& rhs) noexcept;
		Matrix4x4& operator/=(const float& rhs);
		Matrix4x4& operator*=(const Matrix4x4& rhs) noexcept;

		friend Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs);
		friend Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs);
		friend Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs);
		friend Matrix4x4 operator*(const Matrix4x4& lhs, const float& rhs);
	};


}
#endif // !MATRIX4X4_H
