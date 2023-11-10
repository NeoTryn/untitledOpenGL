#pragma once

#include "Shader.h"
#include "Window.h"
#include "FileHandler.h"
#include "VAO.h"
#include "VBO.h"

#include <iostream>
#include <map>

#ifndef GAME
#define GAME

class Game
{
public:
	Window window = {800, 600, "myWin"};
	Shader shader = {};

	VBO vbo;
	VAO vao;
	
	unsigned int VAO, VBO;

	Game();

	void setup();

	void run();

	void update();
	void render();
	void clear();

	void clean();
};

#endif