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

	const int c_ScreenWidth = 640;
	const int c_ScreenHeight = 480;

};

