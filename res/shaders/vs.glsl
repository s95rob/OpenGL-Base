#version 330 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec2 a_uv;

out vec2 o_texCoord;

uniform mat4 u_model,
			 u_view,
			 u_projection;

void main() {
	gl_Position = (u_projection * u_view * u_model) * vec4(a_pos.x, a_pos.y, a_pos.z, 1.0f);
	o_texCoord = a_uv;
}