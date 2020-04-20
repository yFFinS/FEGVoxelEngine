#pragma once
#ifndef MATERIAL_H__
#define MATERIAL_H__
#include "Shader.h"
#include "Matrix4x4.h"
namespace feg {
	class Material
	{
	private:
		std::shared_ptr<Shader> _shader_ptr;
	public:
		Material() noexcept;
		Material(const Shader& shader) noexcept;
		~Material() noexcept;

		void SetMatrix(const char* name, const Matrix4x4& value);
		void SetVector(const char* name, const Vector4& value);
		void SetFloat(const char* name, const float& value);
	public:
		Shader getShader() const noexcept;
	};
}

#endif // !MATERIAL_H__


