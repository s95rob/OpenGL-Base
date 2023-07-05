#pragma once
#include <unordered_map>
#include <glad/glad.h>
#include "Texture.h"

class TextureCache {
public:
	TextureCache() { s_instance = this; }
	~TextureCache() {
		this->Clear();
	}

	// Load texture into VRAM and return a texture handle
	Texture Load(const char* filepath, unsigned int type = GL_TEXTURE_2D);

	// Delete all loaded textures from VRAM and clear the registry cache
	void Clear() {
		for (const auto& cache_pair : m_cache) {
			glDeleteTextures(1, &cache_pair.second);
		}

		m_cache.clear();
	}

	// Return static instance
	static TextureCache& Get() { return *s_instance; }
private:
	static TextureCache* s_instance;

	// k: texture filepath, v: texture ID in VRAM
	std::unordered_map<const char*, unsigned int> m_cache;
};