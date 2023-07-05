#pragma once
#include <glad/glad.h>

// Texture instances only hold their ID to a texture loaded in VRAM

class Texture {
public:
	Texture() = default;

	void Bind() {
		glBindTexture(m_type, m_id);
	}

	// Interface to TextureCache load
	void Load(const char* filepath, unsigned int type = GL_TEXTURE_2D);

	const unsigned int GetID() { return m_id; }
	const unsigned int GetType() { return m_type; }

	friend class TextureCache;
private:
	unsigned int m_id = 0;
	unsigned int m_type = GL_TEXTURE_2D;
};