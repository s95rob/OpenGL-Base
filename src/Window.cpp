#include "Window.h"
#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);

void Window::Init() {
	m_windowPtr = glfwCreateWindow(
		1280,
		720,
		"OpenGL Window",
		NULL,
		NULL
	);

	if (m_windowPtr == nullptr) {
		std::cout << "Failed to create window\n";
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent((GLFWwindow*)m_windowPtr);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
		exit(-1);
	}

	glfwSwapInterval(1);
	glViewport(0, 0, 1280, 720);
}

void Window::PollEvents() {
	glfwPollEvents();
}

void Window::SwapBuffers() {
	glfwSwapBuffers((GLFWwindow*)m_windowPtr);
}

// glfw window callbacks

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}