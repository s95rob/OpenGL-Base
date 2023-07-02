#pragma once

#include "Window.h"
#include <string>

struct ApplicationInit {
    std::string windowTitle = "OpenGL-Base";
    unsigned int windowWidth  = 800,
                 windowHeight = 800;

};

class Application {
public:
    Application(ApplicationInit appInit);
    virtual ~Application();

    virtual void Run() = 0;


    static Application& Get() { return *s_instance; }
    const Window GetWindow() { return m_window; }
    bool IsRunning() { return m_running; }

protected:
    static Application* s_instance;
    ApplicationInit m_appInit;

    Window m_window;
    bool m_running = false;

};