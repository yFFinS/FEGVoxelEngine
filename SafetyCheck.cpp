#include "SafetyCheck.h"

namespace feg {

	void SafetyCheck::GLClearError() {
		while (glGetError() != GL_NO_ERROR);
	}

	bool SafetyCheck::GLLogCall() {
		while (GLenum error = glGetError()) {
			std::cout << "[OpengGL Error]: " << std::hex << error << std::endl;
			return false;
		}
		return true;
	}
}