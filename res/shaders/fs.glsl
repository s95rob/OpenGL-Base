#version 330 core
out vec4 FragColor;

in vec2 o_texCoord;

uniform sampler2D u_texture;
void main() {
	FragColor = texture(u_texture, o_texCoord);
}