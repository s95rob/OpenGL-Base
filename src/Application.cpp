#include "Application.h"
#include <GLFW/glfw3.h>

Application* Application::s_instance = nullptr;

Application::Application() {
    s_instance = this;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window.Init();

    this->m_running = true;
}

Application::~Application() {
}