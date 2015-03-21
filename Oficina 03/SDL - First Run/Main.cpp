#include "SDL.h"

int main(int argc, char** argv) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *_window;
	_window = SDL_CreateWindow("First Game",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								800, 600,
								SDL_WINDOW_SHOWN);


	system("PAUSE");
	return 0;
}