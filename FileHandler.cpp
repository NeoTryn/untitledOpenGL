#include "FileHandler.h"

std::string FileHandler::readFileString(const char* path) {
	std::ifstream reader(path);

	std::string line, result = "";

	while (std::getline(reader, line)) {
		result += line;
		result += "\n";
	}
	
	return result;
}