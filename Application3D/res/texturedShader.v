#version 330 core

layout (location = 8) in vec3 position;
layout (location = 10) in vec3 color;
layout (location = 12) in vec2 texCoord;

out vec2 v_texCoord;
out vec3 v_color;

uniform mat4 MVP;

void main(){
	gl_Position = MVP * vec4(position,1.0);
	v_texCoord = texCoord;
	v_color = color;
}
