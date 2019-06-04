#include <GLEW/glew.h>
#include <iostream>
#include <string>

using namespace std;

class TextureUtil
{
public:
	TextureUtil();
	virtual ~TextureUtil();

	//loading the texture file
	void load(const string& fileName);

	//using the texture
	void bind();

	//deleting the texture
	void unbind();

	//checking for texture error
	void checkTextureError(unsigned char* imageData,const string fileName);

private:
	GLuint myTexture;
};

