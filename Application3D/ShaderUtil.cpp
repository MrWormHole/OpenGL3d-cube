#include "ShaderUtil.h"

ShaderUtil::ShaderUtil()
{
	cout << "ShaderUtil started" << endl;
}


ShaderUtil::~ShaderUtil()
{
	cout << "ShaderUtil stopped" << endl;
}

unsigned int ShaderUtil::load(const string& vertexShaderFile, const string& fragmentShaderFile) {

	//ifstream ifs_vertexShader(vertexShaderFile);
	//const string file_vertexShader((istreambuf_iterator<char>(ifs_vertexShader)), istreambuf_iterator<char>());
	//ifstream ifs_fragmentShader(fragmentShaderFile);
	//const string file_fragmentShader((istreambuf_iterator<char>(ifs_fragmentShader)), istreambuf_iterator<char>());

	const string file_vertexShader(readFromShaderFile(vertexShaderFile));
	const string file_fragmentShader(readFromShaderFile(fragmentShaderFile));
	programID = glCreateProgram();

	unsigned int vertexShader = getCompiledShader(GL_VERTEX_SHADER, file_vertexShader);
	unsigned int fragmentShader = getCompiledShader(GL_FRAGMENT_SHADER, file_fragmentShader);

	glBindAttribLocation(programID, 8, "position"); //this is for meshUtil to send position data
	glBindAttribLocation(programID, 9, "texCoord"); //this is for meshUtil to send texture position data

	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);

	glLinkProgram(programID);
	checkShaderError(programID, GL_LINK_STATUS, true, "Error: Program linking failed");
	glValidateProgram(programID);
	checkShaderError(programID, GL_LINK_STATUS, true, "Error: Program validating failed");

	glDetachShader(programID,vertexShader);
	glDetachShader(programID,fragmentShader);
	glDeleteShader(vertexShader); 
	glDeleteShader(fragmentShader); 
	return programID;
}

unsigned int ShaderUtil::getCompiledShader(unsigned int shaderType,const string& shaderSource) {
	
	unsigned int shaderID = glCreateShader(shaderType);

	if (shaderID == 0) {
		cerr << "Error: Shader creation failed";
	}

	const GLchar* sourceString[1];
	GLint sourceStringLength[1];
	sourceString[0] = shaderSource.c_str();
	sourceStringLength[0] = shaderSource.length();

	glShaderSource(shaderID, 1, sourceString, sourceStringLength);
	glCompileShader(shaderID);
	checkShaderError(shaderID, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");

	return shaderID;	
}

void ShaderUtil::bind() {
	glUseProgram(programID);
	//locColor = glGetUniformLocation(programID, "color");
	locModel = glGetUniformLocation(programID, "model");
}

void ShaderUtil::unbind() {
	glDeleteProgram(programID);
}

void ShaderUtil::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string & errorMessage) {
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram) {
		glGetProgramiv(shader, flag, &success);
	}
	else {
		glGetShaderiv(shader, flag, &success);
	}

	if (success == GL_FALSE) {
		if (isProgram) {
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else {
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}
		cerr << errorMessage << ": '" << error << "'" << endl;
	}
}

string ShaderUtil::readFromShaderFile(const string& fileName) {

	ifstream file;
	file.open(fileName.c_str());

	string output;
	string line;

	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		cerr << "Unable to read from shader file: " << fileName << endl;
	}

	return output;
}

void ShaderUtil::tint(float value) {
	if (locColor != -1)
	{
		glUniform4f(locColor, value / 1.0f, 0.0f, 1.0f, 1.0f);
	}
	else {
		cout << "can not find location of color variable" << endl;
	}
}
