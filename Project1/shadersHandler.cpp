#include "headers.h"
static Log shadersLogger;

unsigned int CompileShader(unsigned int typeOfShader, const std::string& source)
{
	unsigned int id = glCreateShader(typeOfShader);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	// Error Handling.
	int res;
	glGetShaderiv(id, GL_COMPILE_STATUS, &res);
	if (res == GL_FALSE)
	{
		shadersLogger.Error("Error Compiling ",
			typeOfShader == GL_VERTEX_SHADER ? "Vertex Shader!" : "Fragment Shader!");
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* msg = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, msg);
		shadersLogger.Error(msg ? msg : "Unknow Error!");
		glDeleteShader(id);
		return 0;
	}
	return id;
}

unsigned int CreateShader(const std::string& vertexShader, std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

