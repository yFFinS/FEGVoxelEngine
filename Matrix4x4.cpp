#include "Matrix4x4.h"
#include "Math.h"

namespace feg {

	Matrix4x4::Matrix4x4() noexcept : _elements()
	{
	}

	Matrix4x4::Matrix4x4(const std::array<float, 16> elements) noexcept : _elements(elements)
	{
	}

	Matrix4x4 Matrix4x4::CreateScaleMatrix(const Vector4& scale) noexcept
	{
		std::array<float, 16> elements;
		elements[0] = scale.x;
		elements[5] = scale.y;
		elements[10] = scale.z;
		return Matrix4x4(elements);
	}

	Matrix4x4 Matrix4x4::CreateTranslationMatrix(const Vector4& translation) noexcept
	{
		std::array<float, 16> elements;
		elements[3] = translation.x;
		elements[7] = translation.y;
		elements[11] = translation.z;
		return Matrix4x4(elements);
	}

	Matrix4x4 Matrix4x4::CreateRotationMatrix(const Quaternion& rotation) noexcept
	{
		Quaternion nRot = rotation.Normalized();
		const float& x = nRot.x, y = nRot.y, z = nRot.z, w = nRot.w;
		std::array<float, 16> elements = {
			1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * y + y * w), 0,
			2 * (x * y + z * w), 1 - 2 * (x * x + y * y), 2 * (y * z - x * w), 0,
			2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y), 0,
			0, 0, 0, 1
		};
		return Matrix4x4(elements);
	}

	Matrix4x4 Matrix4x4::CreateViewMatrix(const Vector4& forward, const Vector4& up, const Vector4& right, const Vector4& position) noexcept
	{
		std::array<float, 16> elements;
		elements[0] = right.x;
		elements[1] = right.y;
		elements[2] = right.z;
		elements[4] = up.x;
		elements[5] = up.y;
		elements[6] = up.z;
		elements[8] = forward.x;
		elements[9] = forward.y;
		elements[10] = forward.z;
		return Matrix4x4(elements) * CreateTranslationMatrix(-position);
	}

	Matrix4x4 Matrix4x4::CreatePerspectiveProjectionMatrix(const float& width, const float& height, const float& fov, const float& zNear, const float& zFar) noexcept
	{
		std::array<float, 16> elements;
		elements[0] = (1.0f / std::tan((fov * Math::PI / 180.0f) / 2.0f)) / (width / height);
		elements[5] = 1.0f / std::tan((fov * Math::PI / 180.0f) / 2.0f);
		elements[10] = (zNear + zFar) / (zNear - zFar);
		elements[11] = (2.0f * zNear * zFar) / (zNear - zFar);
		elements[14] = -1.0f;
		return Matrix4x4(elements);
	}

	Matrix4x4 Matrix4x4::CreateOrthographicProjectionMatrix(const float& left, const float& right, const float& top, const float& bottom, const float& zNear, const float& zFar) noexcept
	{
		std::array<float, 16> elements;
		elements[0] = 2.0f / (right - left);
		elements[3] = -((right + left) / (right - left));
		elements[5] = 2.0f / (top - bottom);
		elements[7] = -((top + bottom) / (top - bottom));
		elements[10] = 2.0f / (zFar - zNear);
		elements[11] = -((zFar + zNear) / (zFar - zNear));
		return Matrix4x4(elements);
	}

	Matrix4x4 Matrix4x4::CreateTRSMatrix(const Vector4& translation, const Quaternion& rotation, const Vector4& scale) noexcept
	{
		return Matrix4x4::CreateTranslationMatrix(translation) * Matrix4x4::CreateRotationMatrix(rotation) * Matrix4x4::CreateScaleMatrix(scale);
	}

	void Matrix4x4::SetRow(const unsigned char& row, Vector4 values)
	{
		ASSERT(0 <= row && row <= 3);
#pragma warning(disable:26451)
		_elements[row * 4] = values.x;
		_elements[row * 4 + 1] = values.y;
		_elements[row * 4 + 2] = values.z;
		_elements[row * 4 + 3] = values.w;
#pragma warning(default:26451)
	}

	void Matrix4x4::SetColumn(const unsigned char& col, Vector4 values)
	{
		ASSERT(0 <= col && col <= 3);
#pragma warning(disable:26451)
		_elements[col] = values.x;
		_elements[col + 4] = values.y;
		_elements[col + 8] = values.z;
		_elements[col + 12] = values.w;
#pragma warning(default:26451)
	}

	Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs)
	{
		return Matrix4x4(lhs) += rhs;
	}

	Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs)
	{
		return Matrix4x4(lhs) -= rhs;
	}

	Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
	{
		return Matrix4x4(lhs) *= rhs;
	}

	Matrix4x4 operator*(const Matrix4x4& lhs, const float& rhs)
	{
		return Matrix4x4(lhs) *= rhs;
	}
	Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& rhs) noexcept {
		for (unsigned char i = 0; i < 16; i++) {
			_elements[i] += rhs._elements[i];
		}
		return *this;
	}
	Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& rhs) noexcept {
		for (unsigned char i = 0; i < 16; i++) {
			_elements[i] -= rhs._elements[i];
		}
		return *this;
	}
	Matrix4x4& Matrix4x4::operator*=(const float& rhs) noexcept {
		for (unsigned char i = 0; i < 16; i++) {
			_elements[i] *= rhs;
		}
		return *this;
	}
	Matrix4x4& Matrix4x4::operator/=(const float& rhs) {
		ASSERT(rhs != 0);
		for (unsigned char i = 0; i < 16; i++) {
			_elements[i] /= rhs;
		}
		return *this;
	}
	Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& rhs) noexcept {
		std::array<float, 16> arrayCopy = rhs._elements;
		for (unsigned char i = 0; i < 16; i++)
		{
			unsigned char temp1 = i / 4 * 4;
			unsigned char temp2 = i % 4;
			_elements[i] =
#pragma warning(disable:26451)
				arrayCopy[temp1] * rhs._elements[temp1]
				+ arrayCopy[temp1 + 1] * rhs._elements[4 + temp2]
				+ arrayCopy[temp1 + 2] * rhs._elements[8 + temp2]
				+ arrayCopy[temp1 + 3] * rhs._elements[12 + temp2];
#pragma warning(default:26451)
		}
		return *this;
	}

}