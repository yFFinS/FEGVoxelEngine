#include "Matrix4x4.h"
constexpr float PI = 3.14;

namespace feg {

	Matrix4x4::Matrix4x4() noexcept : _elements()
	{
	}

	Matrix4x4::Matrix4x4(const std::array<float, 16> elements) noexcept : _elements(elements)
	{
	}

	Matrix4x4 Matrix4x4::CreateScaleMatrix(const Vector4& scale) noexcept
	{
		Matrix4x4 mat;
		mat._elements[0] = scale.x;
		mat._elements[5] = scale.y;
		mat._elements[10] = scale.z;
		return mat;
	}

	Matrix4x4 Matrix4x4::CreateTranslationMatrix(const Vector4& translation) noexcept
	{
		Matrix4x4 mat;
		mat._elements[3] = translation.x;
		mat._elements[7] = translation.y;
		mat._elements[11] = translation.z;
		return mat;
	}

	Matrix4x4 Matrix4x4::CreateViewMatrix(const Vector4& forward, const Vector4& up, const Vector4& right, const Vector4& position) noexcept
	{
		Matrix4x4 mat1;
		mat1._elements[0] = right.x;
		mat1._elements[1] = right.y;
		mat1._elements[2] = right.z;
		mat1._elements[4] = up.x;
		mat1._elements[5] = up.y;
		mat1._elements[6] = up.z;
		mat1._elements[8] = forward.x;
		mat1._elements[9] = forward.y;
		mat1._elements[10] = forward.z;

		Matrix4x4 mat2;
		mat2._elements[3] = -position.x;
		mat2._elements[7] = -position.y;
		mat2._elements[11] = -position.z;

		Matrix4x4 mat3 = mat1 * mat2;
		return mat3;
	}

	Matrix4x4 Matrix4x4::CreatePerspectiveProjectionMatrix(const float& width, const float& height, const float& fov, const float& zNear, const float& zFar) noexcept
	{
		Matrix4x4 mat;
		mat._elements[0] = (1.0f / std::tan((fov * PI / 180.0f) / 2.0f)) / (width / height);
		mat._elements[5] = 1.0f / std::tan((fov * PI / 180.0f) / 2.0f);
		mat._elements[10] = (zNear + zFar) / (zNear - zFar);
		mat._elements[11] = (2.0f * zNear * zFar) / (zNear - zFar);
		mat._elements[14] = -1.0f;
		return mat;
	}

	Matrix4x4 Matrix4x4::CreateOrthographicProjectionMatrix(const float& left, const float& right, const float& top, const float& bottom, const float& zNear, const float& zFar) noexcept
	{
		Matrix4x4 mat;
		mat._elements[0] = 2.0f / (right - left);
		mat._elements[3] = -((right + left) / (right - left));
		mat._elements[5] = 2.0f / (top - bottom);
		mat._elements[7] = -((top + bottom) / (top - bottom));
		mat._elements[10] = 2.0f / (zFar - zNear);
		mat._elements[11] = -((zFar + zNear) / (zFar - zNear));
		return mat;
	}

	void Matrix4x4::SetRow(const unsigned char& row, Vector4 values)
	{
		ASSERT(0 <= row <= 3);
		_elements[row * 4] = values.x;
		_elements[row * 4 + 1] = values.y;
		_elements[row * 4 + 2] = values.z;
		_elements[row * 4 + 3] = values.w;
	}

	void Matrix4x4::SetColumn(const unsigned char& col, Vector4 values)
	{
		ASSERT(0 <= col <= 3);
		_elements[col] = values.x;
		_elements[col + 4] = values.y;
		_elements[col + 8] = values.z;
		_elements[col + 12] = values.w;
	}

	Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs)
	{
		Matrix4x4 mat(lhs);
		mat += rhs;
		return mat;
	}

	Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs)
	{
		Matrix4x4 mat(lhs);
		mat -= rhs;
		return mat;
	}

	Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
	{
		Matrix4x4 mat(lhs);
		mat *= rhs;
		return mat;
	}

	Matrix4x4 operator*(const Matrix4x4& lhs, const float& rhs)
	{
		Matrix4x4 mat(lhs);
		mat *= rhs;
		return mat;
	}

}