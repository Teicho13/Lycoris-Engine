#include "Window.h"



namespace Lycoris
{
	static GLFWwindow* g_Window = nullptr;
	
	static void glfw_error_callback(int i, const char* c)
	{
	}

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
	{
		glViewport(0, 0, width, height);
	}
	
	int Window::Create()
	{

		glfwSetErrorCallback(glfw_error_callback);
		if (!glfwInit())
		{
			return -1;
		}


		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		int width = 1920;
		int height = 1080;

		GLFWmonitor* pMonitor = NULL;

		g_Window = glfwCreateWindow(width, height, "Lycoris", pMonitor, NULL);


		if (g_Window == nullptr)
		{
			glfwTerminate();

			return -1;
		}

		glfwMakeContextCurrent(g_Window);



		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			return -1;
		}

		glViewport(0, 0, width, height);

		glfwSetFramebufferSizeCallback(g_Window, framebuffer_size_callback);

		return 0;
	}
	void Window::Destroy()
	{
		glfwDestroyWindow(g_Window);
		glfwTerminate();
	}
	void Window::Clear()
	{
		glClearColor(0.20f, 0.52f, 0.92f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Window::Update()
	{
		//Clear screen
		Clear();

		//Process Input
		PollEvents();

		//Display the screen
		Display();
	}
	void Window::Display()
	{
		glfwSwapBuffers(g_Window);
	}
	bool Window::IsOpen()
	{
		return !glfwWindowShouldClose(g_Window);
	}
	void Window::Close()
	{
		glfwSetWindowShouldClose(g_Window, true);
	}
	void Window::PollEvents()
	{
		glfwPollEvents();

		if (glfwGetKey(g_Window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(g_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			Close();
	}
	GLFWwindow* Window::GetWindow()
	{
		return g_Window;
	}
}