#include "display.h"

Display::Display(int width, int height, const std::string& title) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	myWindow = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL);
	myGLContext = SDL_GL_CreateContext(myWindow);

	GLenum status = glewInit();

	if (status != GLEW_OK) {
		std::cerr << "GLEW failed to initialize!" << std::endl;
	}

	closed = false;
}

Display::~Display() {
	SDL_GL_DeleteContext(myGLContext);
	SDL_DestroyWindow(myWindow);
	SDL_Quit();
}

void Display::clear(float r,float g,float b,float a)
{
	glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::isClosed() {
	return closed;
}

void Display::update()
{
	SDL_GL_SwapWindow(myWindow);

	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			closed = true;
		}
	}
}

