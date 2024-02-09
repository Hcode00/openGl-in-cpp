#include "headers.h"

const  int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;



int main()
{
	Log mainLogger;

	GLFWwindow* window;
	/* Initialize the library */
	if (!glfwInit())
	{
		mainLogger.Error("Error Initializing GLFW!");
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HCode", NULL, NULL);
	if (!window)
	{
		mainLogger.Error("Error Initializing GLFW Window!");
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	/* Initialize GLEW */
	auto err = glewInit();
	if (GLEW_OK != err)
	{
		mainLogger.Error("Error Initializing GLEW!");
		return -1;
	}
	mainLogger.Info("Status: Using OpenGL " , glGetString(GL_VERSION));

	float positions[6] = {
		-0.5f,-0.5f,
		0.0f, 0.5f,
		0.5f,-0.5f
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER,buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float),NULL);
  auto vertexShader = readShaderFile("res/shaders/basicVertex.shader");
  auto fragmentShader = readShaderFile("res/shaders/basicFragment.shader");
  auto shader = CreateShader(vertexShader, fragmentShader);
  glUseProgram(shader);


  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES,0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

  glDeleteShader(shader);
	mainLogger.Warn("A call for session termination!");
	glfwTerminate();
	mainLogger.Warn("Session terminated!");

}

