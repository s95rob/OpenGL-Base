#include "Application.h"
#include <glad/glad.h>

class ExampleApp : public Application {
public:
    virtual void Run() override;
};

void ExampleApp::Run() {
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    
    while (this->IsRunning()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->m_window.SwapBuffers();
    }
}

int main() {
    Application* app = new ExampleApp();

    app->Run();

    return 0;
}