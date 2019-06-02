

#include <GLEW/glew.h>
//
#include <iostream>
#include <string>


using namespace std;

class TextureUtil
{
public:
	TextureUtil();
	virtual ~TextureUtil();

	void load(const string& fileName);

	void bind();

	void unbind();

private:
	GLuint myTexture;
};

