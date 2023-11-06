#pragma once

#include <GLFW/glfw3.h>

#ifndef WINDOW
#define WINDOW

class Window
{
public:
	Window(int width, int height, const char* name);
	Window(const char* name);
	Window();

	void destroy();
public:
	GLFWwindow* window;
};

#endif