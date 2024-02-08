#include "vec2.h"
#include "logger.h"
#include "headers.h"

const  int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
	Log logger;

	GLFWwindow* window;
	/* Initialize the library */
	if (!glfwInit())
	{
		logger.Error("Error Initializing GLFW!");
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HCode", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		logger.Error("Error Initializing GLFW Window!");
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	/* Initialize GLEW */
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		logger.Error("Error Initializing GLEW!");
    return -1;
	}
	logger.Info("Status: Using OpenGL " , glGetString(GL_VERSION));
	float positions[6] = {
		-0.5f,-0.5f,
		0.0f, 0.5f,
		0.5f,-0.5f
	};
  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER,buffer);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float),positions, GL_STATIC_DRAW);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.7f, 0.9f, 1.0f);
		//
		glDrawArrays(GL_TRIANGLES, 0, 3);


		//
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	logger.Warn("A call for session termination!");
	glfwTerminate();
	logger.Warn("Session terminated!");

}

