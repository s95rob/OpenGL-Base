#pragma once
#include <glm/glm.hpp>

struct ShaderData {
	unsigned int id = 0;
	int type = 0;
	bool valid = false;

	void Load(const char* filepath);
};

class Shader {
public:
	Shader(const char* vs_filepath, const char* fs_filepath);

	void Use();

	void SetMat4(const char* location, glm::mat4 matrix);
private:
	unsigned int m_programID = 0;
	ShaderData m_vertexShader,
			   m_fragmentShader;
};