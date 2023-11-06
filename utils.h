#pragma once
#include "callbacks.h"

static void glfw_init() {
	glfwSetErrorCallback(glfw_error_callback);

	glfwInit();
}

static void glad_init() {
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}