#include "Common.h"
#include <GLFW/glfw3.h>

#define V_COLOR_BLUE	0.0f, 0.0f, 1.0f
#define V_COLOR_MAGENTA 1.0f, 0.0f, 1.0f
#define V_COLOR_BLACK	0.5f, 0.0f, 0.5f,

GL_EXAMPLE_DECLARE("VertexColors")

GL_EXAMPLE_IMPLEMENTATION {

	float vertices[] = {
		// positions	   // colors
		-1.0f, 1.0f, 0.0f,		V_COLOR_BLUE,			// top left		0
		0.0f, 1.0f, 0.0f,		V_COLOR_MAGENTA,		// top mid		1
		1.0f, 1.0f, 0.0f,		V_COLOR_BLUE,			// top right	2
		1.0f, 0.0f, 0.0f,		V_COLOR_MAGENTA,		// mid right	3
		1.0f, -1.0f, 0.0f,		V_COLOR_BLUE,			// bottom right	4
		0.0f, -1.0f, 0.0f,		V_COLOR_MAGENTA,		// bottom mid	5
		-1.0f, -1.0f, 0.0f,		V_COLOR_BLUE,			// bottom left	6
		-1.0f, 0.0f, 0.0f,		V_COLOR_MAGENTA,		// mid left		7
		0.0f, 0.0f, 0.0f,		V_COLOR_BLACK			// dead center	8
	};

	unsigned int indices[] = {
		0, 1, 8,
		1, 2, 8,
		2, 3, 8,
		3, 4, 8,
		
		4, 5, 8,
		5, 6, 8,
		6, 7, 8,
		7, 0, 8
	};

	unsigned int VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
	glEnableVertexAttribArray(0);

	// Color attribute in generic vertex shader is in layout 3
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));
	glEnableVertexAttribArray(3);

	Shader shader("shaders/vs_generic.glsl", "shaders/fs_color.glsl");
	shader.Use();

	glm::mat4 model;
	float scale = 1;

	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	while (this->IsRunning()) {
		m_window.PollEvents();

		// update matrix
		
		scale = sinf((float)(glfwGetTime()));
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(scale + 2.5f));
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

		shader.SetMat4("u_model", model);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);

		m_window.SwapBuffers();
	}
}