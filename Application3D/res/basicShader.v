#version 330 core

layout (location = 8) in vec3 position;
//layout (location = 10) in vec3 color;
vec3 rndColor;

out vec3 color0;

uniform mat4 MVP;

float random (vec2 test)
 {
    return fract(sin(dot(test,vec2(12.9898,78.233)))*43758.5453123);
 }

void main(){
    rndColor = vec3(random(position.xy),random(position.yz),random(position.xz));
	gl_Position = MVP * vec4(position,1.0);
	//color0 = color;
	color0 = rndColor;
}
