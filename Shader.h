#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "FileHandler.h"

#define SHADERPROGRAM -1

#ifndef SHADER
#define SHADER

class Shader
{
private:
	FileHandler handler;

	static void checkShaderCompilation(unsigned int shader, unsigned long long shaderType);

public:
	unsigned int shaderProgram;
	Shader() = default;

	void setup(const char* vsPath, const char* fsPath);

	void use();

	void setBool(std::string uniformName, bool boolToSet);
	void setInt(std::string uniformName, int intToSet);
	void setFloat(std::string uniformName, float floatToSet);
	
	void setVec2(std::string uniformName, glm::vec2 vecToSet);
	void setVec3(std::string uniformName, glm::vec3 vecToSet);
	void setVec4(std::string uniformName, glm::vec4 vecToSet);

	void setMat2(std::string uniformName, glm::mat2 matToSet);
	void setMat3(std::string uniformName, glm::mat3 matToSet);
	void setMat4(std::string uniformName, glm::mat4 matToSet);
};
#endif