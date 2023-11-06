#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

static void glfw_error_callback(int error, const char* info) {
	std::cout << "Error: " << error << "\nInfoLog: " << info << std::endl;
}