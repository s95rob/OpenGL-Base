#pragma once
#include <GLBase.h>

#define GL_EXAMPLE_DECL(name) \
	class ExampleApp : public Application { \
	public: using Application::Application; virtual void Run() override; }; \
	int main() { \
	ApplicationInit appInit; appInit.windowTitle = "GL Example: " + std::string(name); \
	ExampleApp* app = new ExampleApp(appInit); app->Run(); delete app; return 0; } 

#define GL_EXAMPLE_IMPLEMENTATION void ExampleApp::Run()