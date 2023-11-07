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

	std::map<std::string, VAO> VAOs;
	std::map<std::string, VBO> VBOs;

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