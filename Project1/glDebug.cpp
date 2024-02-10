#include "headers.h"

static Log debugLogger;

void GLClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum err = glGetError())
	{
		debugLogger.sGLError(err,function,file,line);
		return false;
	}
	return true;
}