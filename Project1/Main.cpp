#include "headers.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define  GLCall(x) GLClearErrors();\
	x;\
	ASSERT(GLLogCall(#x,__FILE__,__LINE__))


const  int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

const float aspectRatio = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;

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
	mainLogger.Info("Status: Using OpenGL ", glGetString(GL_VERSION));

	float positions[] = {
		-0.5f,-0.5f,
		0.5f,-0.5f,
		0.5f, 0.5f,
		-0.5f,0.5f,
	};
	unsigned int indices[6] = {
		0,1,2,2,3,0
	};

	GLCall(glfwSwapInterval(1));
	unsigned int buffer;
	GLCall(glGenBuffers(1, &buffer));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), positions, GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL));

	unsigned int ibo;
	GLCall(glGenBuffers(1, &ibo));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_READ));


	auto vertexShader = readShaderFile("res/shaders/basicVertex.shader");
	auto fragmentShader = readShaderFile("res/shaders/basicFragment.shader");
	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	GLCall(glUseProgram(shader));
	GLCall(int myColorId = glGetUniformLocation(shader, "myColor"));
	ASSERT(myColorId != -1);
	float red = 1.0f;
	float blue = 0.0f;
	float rIncrement = -0.05f;
	float bIncrement = 0.01f;


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
		GLCall(glUniform4f(myColorId, red, 0.3f, blue, 1.0f));
		if (red > 1.0f || red < 0.0f) {
			rIncrement = -rIncrement;
		}
		if (blue > 1.0f || blue < 0.0f) {
			bIncrement = -bIncrement;
		}
		red += rIncrement;
		blue += bIncrement;
		GLCall(glfwSwapBuffers(window));
		GLCall(glfwPollEvents());
	}

	glDeleteShader(shader);
	mainLogger.Warn("A call for session termination!");
	glfwTerminate();
	mainLogger.Warn("Session terminated!");

}

