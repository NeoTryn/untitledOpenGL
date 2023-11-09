#pragma once

#include <glad/glad.h>

#include <vector>

#ifndef VBO_CLASS
#define VBO_CLASS

class VBO
{
public:
	unsigned int vbo;

	VBO();
	~VBO() = default;

	void setup();

	void bind();

	void updateData(float data[], float(&pointer)[]);
};

#endif