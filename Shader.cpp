#include "Shader.h"
#include <GL/gl3w.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "SafetyCheck.h"

namespace feg {

	Shader::~Shader()
	{
		if (_vertexShaderId != 0)
			GLCALL(glDeleteShader(_vertexShaderId));
		if (_fragmentShaderId != 0)
			GLCALL(glDeleteShader(_fragmentShaderId));
		if (_programId != 0)
			GLCALL(glDeleteProgram(_programId));
	}

	Shader::Shader()
	{
		GLCALL(_vertexShaderId = glCreateShader(GL_VERTEX_SHADER));
		GLCALL(_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER));
		GLCALL(_programId = glCreateProgram());
	}

	Shader::Shader(const char* vertexShaderCode, const char* fragmentShaderCode) : Shader()
	{
		if (Compile(_vertexShaderId, vertexShaderCode) && Compile(_fragmentShaderId, fragmentShaderCode)) {
			GLCALL(glAttachShader(_programId, _vertexShaderId));
			GLCALL(glAttachShader(_programId, _fragmentShaderId));
			GLCALL(glLinkProgram(_programId));
			GLCALL(glValidateProgram(_programId));

			GLint result;
			int logLength;
			GLCALL(glGetProgramiv(_programId, GL_LINK_STATUS, &result));
			GLCALL(glGetProgramiv(_programId, GL_INFO_LOG_LENGTH, &logLength));
			if (logLength > 0) {
				std::vector<char> errMsg(logLength);
				GLCALL(glGetProgramInfoLog(_programId, logLength, NULL, &errMsg[0]));
				fprintf(stdout, "%s\n", &errMsg[0]);
			}
		}
		GLCALL(glDeleteShader(_vertexShaderId));
		GLCALL(glDeleteShader(_fragmentShaderId));
	}

	enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

	Shader Shader::Parse(const char* shaderFile)
	{
		std::string vertexShaderCode, fragmentShaderCode, line;
		std::ifstream shaderStream(shaderFile, std::ios::in);
		ShaderType type(ShaderType::NONE);
		while (std::getline(shaderStream, line)) {
			if (line.find("#shader") != std::string::npos) {
				if (line.find("vertex") != std::string::npos)
					type = ShaderType::VERTEX;
				else if (line.find("fragment") != std::string::npos)
					type = ShaderType::FRAGMENT;
				else
					type = ShaderType::NONE;
				continue;
			}
			if (type == ShaderType::VERTEX) {
				vertexShaderCode += line + "\n";
			}
			else if (type == ShaderType::FRAGMENT) {
				fragmentShaderCode += line + "\n";
			}
		}
		shaderStream.close();
		return Shader(vertexShaderCode.c_str(), fragmentShaderCode.c_str());
	}

	bool Shader::Compile(unsigned int shaderId, const char* shaderCode) {
		GLint result = GL_FALSE;
		GLint logLength;
		GLCALL(glShaderSource(shaderId, 1, &shaderCode, nullptr));
		GLCALL(glCompileShader(shaderId));

		GLCALL(glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result));
		GLCALL(glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength));
		if (logLength > 0) {
			std::vector<char> errMsg(logLength);
			GLCALL(glGetShaderInfoLog(shaderId, logLength, NULL, &errMsg[0]));
			fprintf(stdout, "%s\n", &errMsg[0]);
			return false;
		}
		return true;
	}

	void Shader::Bind() const
	{
		ASSERT(_programId != 0);
		GLCALL(glUseProgram(_programId));
	}

	void Shader::Unbind() const
	{
#ifndef NDEBUG
		GLCALL(glUseProgram(0));
#endif // !NDEBUG
	}

	unsigned int Shader::GetUniformIndex(const char*& name) const
	{
		unsigned int index;
		GLCALL(index = glGetUniformBlockIndex(_programId, name));
		return index;
	}

}