#include "logger.h"
#include "headers.h"

Log logger;


static unsigned int CompileShader(unsigned int typeOfShader,const std::string& source)
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
		logger.Error("Error Compiling " ,
			typeOfShader == GL_VERTEX_SHADER ? "Vertex Shader!":"Fragment Shader!");
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* msg = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, msg);
		logger.Error(msg ? msg : "Unknow Error!");
		glDeleteShader(id);
		return 0;
	}
	return id;
}

static unsigned int CreateShader(const std::string& vertexShader, std::string& fragmentShader)
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



const  int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{

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
		logger.Error("Error Initializing GLFW Window!");
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	/* Initialize GLEW */
	auto err = glewInit();
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

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER,buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float),NULL);


  // write the shaders and apply them
  std::string vertexShader =
	  "#version 450 core\n"
	  "layout(location = 0) in vec4 position;\n"
	  "void main()\n"
	  "{\n"
	  "	gl_Position = position;\n"
	  "}\n";

  std::string fragmentShader =
	  "#version 450 core\n"
	  "layout(location = 0) out vec4 color;\n"
	  "void main()\n"
	  "{\n"
	  "	color = vec4(0.5,0.2,0.8,1.0);\n"
	  "}\n";

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
	logger.Warn("A call for session termination!");
	glfwTerminate();
	logger.Warn("Session terminated!");

}

