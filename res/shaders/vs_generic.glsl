#version 330 core
layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec3 a_norm;
layout (location = 2) in vec2 a_uv;
layout (location = 3) in vec3 a_color;

out vec3 o_normals;
out vec2 o_texCoord;
out vec3 o_color;

uniform mat4 u_model = mat4(1.0f),
			 u_view = mat4(1.0f),
			 u_projection = mat4(1.0f);

void main() {
	gl_Position = (u_projection * u_view * u_model) * vec4(a_pos.x, a_pos.y, a_pos.z, 1.0f);
	o_normals = a_norm;
	o_texCoord = a_uv;
	o_color = a_color;
}