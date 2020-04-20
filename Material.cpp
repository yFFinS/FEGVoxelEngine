#include "Material.h"
#include "SafetyCheck.h"

namespace feg {

	Material::Material() noexcept
	{
	}

	Material::Material(const Shader& shader) noexcept : _shader_ptr(std::make_shared<Shader>(shader))
	{
	}

	Material::~Material() noexcept
	{
	}

	void Material::SetMatrix(const char* name, const Matrix4x4& value)
	{
		glUniformMatrix4fv(getShader().GetUniformIndex(name), 1, GL_FALSE, value.GetElementsPtr());
	}

	void Material::SetVector(const char* name, const Vector4& value)
	{
	}

	void Material::SetFloat(const char* name, const float& value)
	{
	}

	Shader Material::getShader() const noexcept
	{
		return *_shader_ptr;
	}

}