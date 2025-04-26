#include <iostream>
#include <GLFW/glfw3.h>

int main() {
	GLFWwindow* Window;
	if (!glfwInit())
	{
		return -1;
	}

	Window = glfwCreateWindow(640, 480, "Hello Window", NULL, NULL);

	if (!Window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(Window);

	while (!glfwWindowShouldClose(Window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(Window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}