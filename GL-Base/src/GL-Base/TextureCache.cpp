#include "TextureCache.h"
#include "Log.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

TextureCache* TextureCache::s_instance = nullptr;

Texture TextureCache::Load(const char* filepath, unsigned int type) {
	Texture new_tex;
	new_tex.m_type = type;

	// Check if texture is already in registry, 
	// Return a handle with that texture ID if it is
	if (m_cache.count(filepath) > 0) {
		new_tex.m_id = m_cache[filepath];
		return new_tex;
	}

	// Otherwise load the texture into VRAM and return a handle

	stbi_set_flip_vertically_on_load(true);
	int width, height, num_channels;
	void* data = stbi_load(filepath, &width, &height, &num_channels, 0);

	if (data == nullptr) {
		Log::Error("Failed to load texture: " + std::string(filepath));
		return new_tex;
	}

	// Generate texture unit in VRAM
	glGenTextures(1, &new_tex.m_id);
	glBindTexture(new_tex.m_type, new_tex.m_id);

	glTexParameteri(new_tex.m_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(new_tex.m_type, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(new_tex.m_type,
		GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(new_tex.m_type,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Check if alpha channel is available, load data into texture unit in VRAM
	unsigned int image_format = (num_channels == 4 ? GL_RGBA : GL_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, image_format, width, height, 0, image_format,
		GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(new_tex.m_type);

	// Register the texture in the cache and free texture data from RAM
	m_cache[filepath] = new_tex.m_id;
	free(data);

	return new_tex;
}