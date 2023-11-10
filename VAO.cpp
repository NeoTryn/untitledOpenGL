#include "VAO.h"

VAO::VAO() {
	vao = 0;
}

void VAO::setup() {
	glGenVertexArrays(1, &vao);
}

void VAO::bind() {
	glBindVertexArray(VAO::vao);
}