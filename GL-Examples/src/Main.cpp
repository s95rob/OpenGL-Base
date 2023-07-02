#include <GLBase.h>

unsigned int VAO, VBO, EBO;

float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  
	0, 1, 3,   
	1, 2, 3    
};

class ExampleApp : public Application {
public:
	using Application::Application;
	virtual void Run() override;
private:
};

void ExampleApp::Run() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
	glEnableVertexAttribArray(0);

	Shader shader("shaders/vs.glsl", "shaders/fs.glsl");
	shader.Use();

	glm::mat4 proj, view, model;
	proj = view = model = glm::mat4(1.0f);

	proj = glm::perspective(70.0f, 
		m_window.GetSize().x / m_window.GetSize().y, 0.1f, 100.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));

	shader.SetMat4("u_mvp", (proj * view * model));

	while (this->IsRunning()) {
		m_window.PollEvents();

		glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		m_window.SwapBuffers();
	}
}

int main() {
	ApplicationInit appInit;
	appInit.windowTitle = "GL Example";

	ExampleApp* app = new ExampleApp(appInit);

	app->Run();

	delete app;

	return 0;
}