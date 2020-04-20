#include "Application.h"
#include "Time.h"
#include <string>
#include "Renderer.h"

namespace feg {
	unsigned int Application::_width;
	unsigned int Application::_height;
	GLFWwindow* Application::window = NULL;
	Event Application::onUpdate;

	bool Application::Initialize(const int& width, const int& height, const char* title)
	{
		if (!glfwInit()) {
			fprintf(stderr, "Can't init GLFW.");
			return false;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);
		_width = width;
		_height = height;
		window = glfwCreateWindow(_width, _height, title, NULL, NULL);
		if (window == NULL) {
			fprintf(stderr, "Can't create window.");
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(window);

		if (gl3wInit() != GL3W_OK) {
			fprintf(stderr, "Can't init GL3W.");
			return false;
		}

		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
		std::cout << glGetString(GL_VERSION) << std::endl;
		return true;
	}

	void Application::Run() {
		do {
			GLCALL(glClear(GL_COLOR_BUFFER_BIT));
			onUpdate.Invoke();
			glfwSwapBuffers(window);
			glfwPollEvents();
			Time::Tick();
		} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == GL_FALSE);
		Close();
	}

	void Application::SetTitle(const char* title)
	{
		glfwSetWindowTitle(window, title);
	}

	void Application::Close()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	unsigned int Application::getWidth() noexcept
	{
		return _width;
	}

	unsigned int Application::getHeight() noexcept
	{
		return _height;
	}

}