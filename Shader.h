#pragma once
#ifndef SHADER_H
#define SHADER_H

namespace feg {

	class Shader
	{
	public:
		~Shader();
		Shader(const char* vertexShaderCode, const char* fragmentShaderCode);

		static Shader Parse(const char* shaderFile);
		static bool Compile(unsigned int shaderId, const char* shaderCode);
		void Use() const;

	private:
		Shader();

	private:
		unsigned int _vertexShaderId;
		unsigned int _fragmentShaderId;
		unsigned int _programId;
	};

}
#endif !SHADER_H