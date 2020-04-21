#pragma once
#ifndef SAFETY_CHECK_H
#define SAFETY_CHECK_H


namespace feg {

	class SafetyCheck
	{
	public:
		static void GLClearError();
		static bool GLLogCall();
		static void Assert(const bool& x, const std::string& message);
	};

#define ASSERT(x) SafetyCheck::Assert(x, "");
#define ASSERT_MSG(x, msg) SafetyCheck::Assert(x, msg);
#define GLCALL(x) SafetyCheck::GLClearError(); x; ASSERT(SafetyCheck::GLLogCall());
}


#endif // !SAFETY_CHECK_H