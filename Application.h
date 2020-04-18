#pragma once
#ifndef APPLICATION_H
#define APPLICATION_h
#include <Windows.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include "Event.h"
#include "VertexArray.h"

namespace feg {
	class Application
	{
	public:
		static bool Initialize(const int& width, const int& height, const char* title);

		static void Run();

		static void SetTitle(const char* title);

		static void Close();

	private:
		static unsigned int _width;
		static unsigned int _height;
	public:
		static GLFWwindow* window;
		static Event onUpdate;
		static VertexArray* vao;

		static unsigned int getWidth() noexcept;
		static unsigned int getHeight() noexcept;
	};

}
#endif // !APPLICATION_H

