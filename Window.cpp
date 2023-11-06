#include "Window.h"

Window::Window(int width, int height, const char* name) {
	Window::window = glfwCreateWindow(width, height, name, nullptr, nullptr);
}

Window::Window(const char* name) {
	Window::window = glfwCreateWindow(800, 600, name, nullptr, nullptr);
}

Window::Window() {
	Window::window = glfwCreateWindow(800, 600, "defaultWin", nullptr, nullptr);
}

void Window::destroy() {
	glfwDestroyWindow(Window::window);
}