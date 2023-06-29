#pragma once

class Window {
public:
	Window() {}

	void Init();
	void SwapBuffers();
private:
	void* m_windowPtr;

};