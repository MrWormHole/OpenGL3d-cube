#include "shader.h"

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);
static string loadShader(const string& fileName);
static GLuint createShader(const string& text, GLenum shaderType);

Shader::Shader(const string& fileName) {
	myProgram = glCreateProgram();
	allShaders[0] = createShader(loadShader(fileName + ".v"), GL_VERTEX_SHADER);
	allShaders[0] = createShader(loadShader(fileName + ".f"), GL_FRAGMENT_SHADER);

	for (int i = 0; i < numberOfShaders; i++) {
		glAttachShader(myProgram, allShaders[i]);
	}

	glBindAttribLocation(myProgram, 0, "position");
	glLinkProgram(myProgram);
	checkShaderError(myProgram, GL_LINK_STATUS, true, "Error: Program linking failed");
	glValidateProgram(myProgram);
	checkShaderError(myProgram, GL_VALIDATE_STATUS, true, "Error: Program validating failed");
}

Shader::~Shader() {
	for (int i = 0; i < numberOfShaders; i++) {
		glDetachShader(myProgram, allShaders[i]);
		glDeleteShader(allShaders[i]);
	}

	glDeleteProgram(myProgram);
}

void Shader::bind() {
	glUseProgram(myProgram);
}

static GLuint createShader(const string& text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0) {
		cerr << "Error: Shader creation failed";
	}
	const GLchar* shaderSourceString[1];
	GLint shaderSourceStringLength[1];
	shaderSourceString[0] = text.c_str();
	shaderSourceStringLength[0] = text.length();

	glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLength);
	glCompileShader(shader);

	checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");

	return shader;
}

void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const string & errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram) {
		glGetProgramiv(shader, flag, &success);
	}
	else {
		glGetShaderiv(shader, flag, &success);
	}

	if (success = GL_FALSE) {
		if (isProgram) {
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else {
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}
		cerr << errorMessage << ": '" << error << "'" << endl;
	}
}

static string loadShader(const string& fileName) {
	
	ifstream file;
	file.open((fileName).c_str());

	string output;
	string line;

	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		cerr << "Unable to load shader: " << fileName << endl;
	}

	return output;
}