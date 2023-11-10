#pragma once

#include <glad/glad.h>

#ifndef VAO_CLASS
#define VAO_CLASS

class VAO
{
public:
	unsigned int vao;

	VAO();
	~VAO() = default;

	void setup();

	void bind();
};

#endif