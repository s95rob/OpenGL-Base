#pragma once

#include "Window.h"
#include <string>

class Application {
public:
    Application();
    virtual ~Application();

    virtual void Run() = 0;

    static Application& Get() { return *s_instance; }
    bool IsRunning() { return m_running; }

protected:

    static Application* s_instance;

    Window m_window;
    bool m_running = false;

};