#include "Texture.h"
#include "TextureCache.h"

void Texture::Load(const char* filepath, unsigned int type) {
	*this = TextureCache::Get().Load(filepath, type);
}