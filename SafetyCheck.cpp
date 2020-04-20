#include "SafetyCheck.h"

namespace feg {

	void SafetyCheck::GLClearError() {
#ifndef NDEBUG
		while (glGetError() != GL_NO_ERROR);
#endif // !NDEBUG
	}

	bool SafetyCheck::GLLogCall() {
#ifndef NDEBUG
		while (GLenum error = glGetError()) {
			std::cout << "[OpengGL Error]: " << std::hex << error << std::endl;
			return false;
		}
#endif // !NDEBUG
		return true;
	}

	void SafetyCheck::Assert(const bool& x)
	{
		if (!(x)) {
			DebugBreak();
		}
	}

}