#version 330 core

in vec3 color0;

out vec4 color;

void main() {
	color = vec4(color0,1);
}
