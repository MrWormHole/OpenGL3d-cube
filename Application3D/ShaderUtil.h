#ifndef SHADER_UTIL_H
#define SHADER_UTIL_H

#include <GLEW/glew.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ShaderUtil
{
public:
	ShaderUtil();
	virtual ~ShaderUtil();

	//loading the vertex and the fragment shader after reading the files
	unsigned int load(const string& vertexShaderFile,const string& fragmentShaderFile,int index);	

	//using the program
	void bind(int index);

	//not using the program
	void unbind();

	//checking for shader errors
	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

	//reading the shader file
	string readFromShaderFile(const string& fileName);

	//changing the color
	void tint(float value);

	inline unsigned int getProgramID(int index) { return programID[index]; }
	inline GLint getLocColor() { return locColor; }
	inline GLint getLocMVP() { return locMVP; }
private:
	unsigned int programID[21]; //lets say we will have 2 shaders for 2 different objects
	GLint locColor;
	GLint locMVP;

	unsigned int getCompiledShader(unsigned int shaderType,	const string& shaderSource);
};

#endif
