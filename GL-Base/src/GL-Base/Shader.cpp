#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include <iostream>

// Shader definitions

Shader::Shader(const char* vs_filepath, const char* fs_filepath) {
	m_programID = glCreateProgram();

	m_vertexShader.type = GL_VERTEX_SHADER;
	m_vertexShader.Load(vs_filepath);
	m_fragmentShader.type = GL_FRAGMENT_SHADER;
	m_fragmentShader.Load(fs_filepath);

	glAttachShader(m_programID, m_vertexShader.id);
	glAttachShader(m_programID, m_fragmentShader.id);
	glLinkProgram(m_programID);

	glDeleteShader(m_vertexShader.id);
	glDeleteShader(m_fragmentShader.id);
}

void Shader::Use() {
	glUseProgram(m_programID);
}

void Shader::SetMat4(const char* location, glm::mat4 matrix) {
	glUniformMatrix4fv(glGetUniformLocation(m_programID, location),
		1, GL_FALSE, glm::value_ptr(matrix));
}

// ShaderData definitions

void ShaderData::Load(const char* filepath) {
	FILE* file = fopen(filepath, "r");
	char* source = nullptr;
	size_t filesize;

	if (file == nullptr) {
		std::cerr << "Failed to load shader file: \"" << filepath << "\"\n";
		return;
	}
	else if (type == 0) {
		std::cerr << "Failed to create shader from file: \"" << filepath << "\"\nType not set!\n";
		return;
	}

	fseek(file, 0, SEEK_END);
	filesize = ftell(file);
	fseek(file, 0, SEEK_SET);

	source = new char[filesize + 1];

	fread(source, sizeof(char), filesize, file);
	source[filesize] = '\0';

	this->id = glCreateShader(type);
	glShaderSource(this->id, 1, &source, NULL);
	glCompileShader(this->id);

	glGetShaderiv(this->id, GL_COMPILE_STATUS, (int*)&valid);
	if (!this->valid) {
		char infoLog[512];
		glGetShaderInfoLog(this->id, 512, NULL, infoLog);
		std::cerr << "Failed to compile shader file: \"" << filepath << "\"\n" << infoLog << "\n";
	}

	delete[] source;
	fclose(file);
}