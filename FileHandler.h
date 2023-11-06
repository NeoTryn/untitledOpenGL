#pragma once

#include <fstream>
#include <iostream>
#include <string>

#ifndef FILEHANDLER
#define FILEHANDLER

class FileHandler
{
public:
	static std::string readFileString(const char* path);
};

#endif