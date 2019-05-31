#version 110

uniform float scale;

void main(void)  
{     
   //vec4 a = gl_Vertex;     
   //a.x = a.x * scale;     
   //a.y = a.y * scale;     
   //gl_Position = gl_ModelViewProjectionMatrix * a;  
   vec4 a = gl_Vertex;
   a.x = a.x * 1.0;
   a.y = a.y * 1.0;
   gl_Position = gl_ModelViewProjectionMatrix * a;
}  
