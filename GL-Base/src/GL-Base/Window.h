#pragma once
#include <glm/glm.hpp>

class Window {
public:
	Window() {}

	void Init(const char* title, unsigned int width, unsigned int height);
	void PollEvents();
	void SwapBuffers();

	glm::vec2 GetSize() { return m_size; }
private:
	void* m_windowPtr;

	glm::vec2 m_size;

};