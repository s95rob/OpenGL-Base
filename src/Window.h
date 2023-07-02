#pragma once

class Window {
public:
	Window() {}

	void Init();
	void PollEvents();
	void SwapBuffers();
private:
	void* m_windowPtr;

};