#include "SafetyCheck.h"

namespace feg {

	void SafetyCheck::GLClearError() {
#ifndef NDEBUG
		while (glGetError() != GL_NO_ERROR);
#endif // !NDEBUG
	}

	bool SafetyCheck::GLLogCall() {
		bool errorFound = false;
#ifndef NDEBUG
		while (GLenum error = glGetError()) {
			std::cout << "[OpengGL Error]: " << std::hex << error << std::endl;
			errorFound = true;
		}
#endif // !NDEBUG
		return !errorFound;
	}

	void SafetyCheck::Assert(const bool& x, const std::string& message)
	{
#ifndef NDEBUG
		if (!(x)) {
			if (message != "")
				std::cout << message << std::endl;
			DebugBreak();
		}
#endif // !NDEBUG
	}
}