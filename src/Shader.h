#pragma once

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
private:
	unsigned int m_programID = 0;
	ShaderData m_vertexShader,
			   m_fragmentShader;
};