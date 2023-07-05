#include <GLBase.h>

class SandboxApp : public Application {
public:
	using Application::Application;
	virtual void Run() override;
};

int main() {
	ApplicationInit appInit;
	appInit.windowTitle = "GL Sandbox";
	appInit.windowWidth = 1280;
	appInit.windowHeight = 720;

	SandboxApp* app = new SandboxApp(appInit);

	app->Run();

	delete app;

	return 0;
}

void SandboxApp::Run() {
	// Initialize buffers/etc. here

	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	while (this->IsRunning()) {
		m_window.PollEvents();

		// Update here

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		// Draw here

		m_window.SwapBuffers();
	}
}