#pragma once
#include <fstream>
#pragma once
#include <sstream>
#pragma once
#include <string>

std::string readShaderFile(const std::string& filepath)
{
	std::ifstream stream(filepath);
	std::stringstream ss[1];
	std::string line;
	while (getline(stream, line))
	{
		ss[0] << line << "\n";
	}
	return ss[0].str();
}