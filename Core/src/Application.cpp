#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Application.h"
#include <iostream>
#include <Shader.h>

Application::Application()
{
}

Application::~Application()
{
}

int Application::Run()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(m_ScreenWidth, m_ScreenHeight, "Pong", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	Shader ourShader("src/Shaders/vertexShader.shader", "src/Shaders/fragmentShader.shader");

	float vertices[] = {
		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // top right
		 0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,// bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// bottom left
		-0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f// top left 
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	unsigned int vertexArrayObject;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	unsigned int vertexBufferObject;
	glGenBuffers(1, &vertexBufferObject);
	//copy vertex array into GL_ARRAY_BUFFER 
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int elementBufferObject;
	glGenBuffers(1, &elementBufferObject);
	// copy index array into GL_ELEMENT_ARRAY_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// link vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	// render in wireframe mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);

		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		ourShader.use();

		//float timeValue = glfwGetTime();
		//float colourValue = sin(timeValue) / 2.0f + 0.5f;
		//int vertexLocation = glGetUniformLocation(shaderProgramId, "ourColour");
		//glUniform4f(vertexLocation, 0.0f, colourValue, 0.0f, 1.0f);

		glBindVertexArray(vertexArrayObject);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &vertexArrayObject);
	glDeleteBuffers(1, &vertexBufferObject);
	glDeleteBuffers(1, &elementBufferObject);
	//glDeleteProgram(shaderProgramId);

	glfwTerminate();

	return 0;

}

void Application::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
