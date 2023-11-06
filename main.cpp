#include <iostream>
#include "utils.h"
#include "Game.h"

int main() {
	
	glfw_init();

	Game game = {};

	glfwMakeContextCurrent(game.window.window);

	glad_init();

	game.run();

	glfwTerminate();
	return 0;
}