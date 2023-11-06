#include "Shader.h"

void Shader::setup(const char* vsPath, const char* fsPath) {
	std::string vertSrcStr = Shader::handler.readFileString(vsPath);
	std::string fragSrcStr = Shader::handler.readFileString(fsPath);

	//std::cout << vertSrcStr << "\n" << fragSrcStr << std::endl;

	const char* vertSrc = vertSrcStr.c_str();
	const char* fragSrc = fragSrcStr.c_str();

	unsigned int vertexShader, fragmentShader;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertSrc, nullptr);
	glCompileShader(vertexShader);

	checkShaderCompilation(vertexShader, GL_VERTEX_SHADER);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragSrc, nullptr);
	glCompileShader(fragmentShader);

	checkShaderCompilation(fragmentShader, GL_FRAGMENT_SHADER);

	Shader::shaderProgram = glCreateProgram();
	glAttachShader(Shader::shaderProgram, vertexShader);
	glAttachShader(Shader::shaderProgram, fragmentShader);
	glLinkProgram(Shader:: shaderProgram);

	checkShaderCompilation(Shader::shaderProgram, SHADERPROGRAM);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::checkShaderCompilation(unsigned int shader, unsigned long long shaderType) {

	int success;
	char infoLog[512];

	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shader, 512, NULL, infoLog);
		if (shaderType == GL_VERTEX_SHADER) {
			std::cout << "Vertex Shader Compilation failed.\n";
		}
		else if (shaderType == GL_FRAGMENT_SHADER) {
			std::cout << "Fragment Shader Compilation failed.\n";
		}
		else {
			std::cout << "Shader Program Compilation failed.\n";
		}
		std::cout << "InfoLog: " << infoLog << std::endl;
	}
}

void Shader::use() {
	glUseProgram(Shader::shaderProgram);
}

void Shader::setBool(std::string uniformName, bool boolToSet) {
	glUniform1i(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), static_cast<int>(boolToSet));
}

void Shader::setInt(std::string uniformName, int intToSet) {
	glUniform1i(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), intToSet);
}

void Shader::setFloat(std::string uniformName, float floatToSet) {
	glUniform1f(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), floatToSet);
}

void Shader::setVec2(std::string uniformName, glm::vec2 vecToSet) {
	glUniform2fv(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), 1,  glm::value_ptr(vecToSet));
}

void Shader::setVec3(std::string uniformName, glm::vec3 vecToSet) {
	glUniform3fv(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), 1, glm::value_ptr(vecToSet));
}

void Shader::setVec4(std::string uniformName, glm::vec4 vecToSet) {
	glUniform4fv(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), 1, glm::value_ptr(vecToSet));
}

void Shader::setMat2(std::string uniformName, glm::mat2 matToSet) {
	glUniformMatrix2fv(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(matToSet));
}

void Shader::setMat3(std::string uniformName, glm::mat3 matToSet) {
	glUniformMatrix3fv(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(matToSet));
}

void Shader::setMat4(std::string uniformName, glm::mat4 matToSet) {
	glUniformMatrix4fv(glGetUniformLocation(Shader::shaderProgram, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(matToSet));
}