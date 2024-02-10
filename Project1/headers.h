#pragma once
#include <iostream>
#pragma once
#include <GLEW/glew.h>
#pragma once
#include <GLFW/glfw3.h>
#pragma once
#include "logger.h"


// FileHandler file definitions
std::string readShaderFile(const std::string& filepath);

// shadersHandler file definitions
unsigned int CompileShader(unsigned int typeOfShader, const std::string& source);

unsigned int CreateShader(const std::string& vertexShader, std::string& fragmentShader);

// glDebug file definitions
void GLClearErrors();

bool GLLogCall( const char* function, const char* file, int line);