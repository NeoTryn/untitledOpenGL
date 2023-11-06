#include "Game.h"

void processInput(Window win);

Game::Game() {
	std::cout << "Game created!\n";
    Game::VAO = 0, Game::VBO = 0;
}

float x,y,z = 0.0f;

void Game::setup() {

	glEnable(GL_DEPTH_TEST);

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

	Game::shader.setup("vertex_shader.txt", "fragment_shader.txt"); 

	Game::shader.use();

	glCreateVertexArrays(1, &VAO);
	glBindVertexArray(Game::VAO);

	glCreateBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, Game::VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Game::render() {
    glBindVertexArray(VAO);
	Game::shader.use();
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Game::update() {
    processInput(Game::window);

	glm::mat4 model = glm::mat4(1.0f), view = glm::mat4(1.0f), projection = glm::mat4(1.0f);

    //model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    model = glm::translate(model, glm::vec3(x, y, z));

    //view = glm::translate(view, glm::vec3(x, y, z));

	view = glm::lookAt(glm::vec3(x, y + 8, z + 5), glm::vec3(x, y, z), glm::vec3(0, 1, 0));

    projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

	Game::shader.setMat4("model", model);
	
	Game::shader.setMat4("view", view);

	Game::shader.setMat4("projection", projection);

    Game::render();

    /*glUniformMatrix4fv(glGetUniformLocation(Game::shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

    glUniformMatrix4fv(glGetUniformLocation(Game::shader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

    glUniformMatrix4fv(glGetUniformLocation(Game::shader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));*/

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));

    Game::shader.setMat4("model", model);

    Game::shader.setMat4("view", view);

    Game::shader.setMat4("projection", projection);

    Game::render();
}

void Game::clean() {
	glfwDestroyWindow(Game::window.window);
}

void Game::clear() {
}

void Game::run() {

	Game::setup();

	while (!glfwWindowShouldClose(Game::window.window)) {
		glfwSwapBuffers(Game::window.window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Game::update();
		Game::clear();

		glfwPollEvents();
	}

	Game::clean();
}


void processInput(Window win) {
    if (glfwGetKey(win.window, GLFW_KEY_W) == GLFW_PRESS) {
        z -= 0.05f;
    }
    if (glfwGetKey(win.window, GLFW_KEY_S) == GLFW_PRESS) {
        z += 0.05f;
    }
    if (glfwGetKey(win.window, GLFW_KEY_A) == GLFW_PRESS) {
        x -= 0.05f;
    }
    if (glfwGetKey(win.window, GLFW_KEY_D) == GLFW_PRESS) {
        x += 0.05f;
    }
}