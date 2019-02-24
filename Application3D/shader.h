#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <GL/glew.h>

using namespace std;

class Shader
{
public:
	Shader(const string& fileName);
	virtual ~Shader();
	void bind();
protected:
private:
	static const unsigned int numberOfShaders = 2; //vertex and fragment shaders(didn't include geometry shader yet)
	GLuint myProgram;
	GLuint allShaders[numberOfShaders];
	Shader(const Shader& other);
	Shader& operator=(const Shader& other);
};

#endif

