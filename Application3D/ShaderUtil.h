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
	unsigned int load(const string& vertexShaderFile,const string& fragmentShaderFile);	

	//using the program
	void bind();

	//deleting the program
	void unbind();

	//checking for shader errors
	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);

	//reading the shader file
	string readFromShaderFile(const string& fileName);

	//changing the color
	void tint(float value);

	inline unsigned int getProgramID() { return programID; }
	inline GLint getLocColor() { return locColor; }
	inline GLint getLocModel() { return locModel; }
private:
	unsigned int programID;
	GLint locColor;
	GLint locModel;

	unsigned int getCompiledShader(unsigned int shaderType,	const string& shaderSource);
};

