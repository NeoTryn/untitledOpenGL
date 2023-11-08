#pragma once

#ifndef VBO_CLASS
#define VBO_CLASS

template<typename T>
class VBO
{
public:
	unsigned int vbo;

	VBO();
	~VBO() = default;

	void setup();

	void addData(T data, unsigned long long DRAW_MODE);

	void bind();
};

#endif