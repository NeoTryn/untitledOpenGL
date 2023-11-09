#include "VBO.h"

VBO::VBO() {
	VBO::vbo = 0;
}

void VBO::setup() {
	glCreateBuffers(1, &vbo);
}

void VBO::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, VBO::vbo);
}

/*void VBO::updateData(float data[], float(&pointer)[]) {
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), pointer, GL_STATIC_DRAW);
}*/