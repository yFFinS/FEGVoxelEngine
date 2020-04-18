#pragma once
#ifndef SAFETY_CHECK_H
#define SAFETY_CHECK_H

#include <GL/gl3w.h>
#include <iostream>
#include <iomanip>

namespace feg {

	class SafetyCheck
	{
	public:
		static void GLClearError();
		static bool GLLogCall();
	};

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCALL(x) SafetyCheck::GLClearError(); x; ASSERT(SafetyCheck::GLLogCall());
}


#endif // !SAFETY_CHECK_H