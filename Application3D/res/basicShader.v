#version 330 core

layout (location = 8) in vec3 position;
layout (location = 10) in vec3 color;

out vec3 color0;

uniform mat4 MVP;

void main(){
	gl_Position = MVP * vec4(position,1.0);
	color0 = color;
}
