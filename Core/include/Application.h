#pragma once
#include <GLFW/glfw3.h>

class Application
{
public:
	Application();
	~Application();
	int Run();
private: 
	/// <summary>
	/// Callback for GLFW when the window size is updated
	/// </summary>
	/// <param name="window"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	/// <summary>
	/// Handle inputs through GLFW
	/// </summary>
	/// <param name="window"></param>
	void ProcessInput(GLFWwindow* window);

	const int m_ScreenWidth = 640;
	const int m_ScreenHeight = 480;
	const char* m_VertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColour;\n"
		"out vec3 ourColour;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"   ourColour = aColour;\n"
		"}\0";
	const char* m_FragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec4 ourColour;"
		"void main()\n"
		"{\n"
		"    FragColor = ourColour;\n"
		"}\0";
};

