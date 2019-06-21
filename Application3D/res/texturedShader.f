#version 330 core

in vec2 v_texCoord;
in vec3 v_color;

//out vec4 color;
out vec4 FragColor;

uniform sampler2D f_texture;

void main() {
	FragColor = texture2D(f_texture, v_texCoord);
	//color = vec4(v_color,255);
}