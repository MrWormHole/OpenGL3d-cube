#version 120

uniform int u_color = 0x6C5CE7;

void main(){
	float rValue = float(u_color / 256 / 256);
	float gValue = float(u_color / 256 - int(rValue * 256.0));
	float bValue = float(u_color - int(rValue * 256.0 * 256.0) - int(gValue * 256.0));
	gl_FragColor = vec4(rValue / 255.0, gValue / 255.0, bValue / 255.0, 1.0);
}
