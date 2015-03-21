#include "SDL.h"
#include <iostream>

int main(int argc, char** argv) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *_window;
	_window = SDL_CreateWindow("First Game",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								800, 600,
								SDL_WINDOW_SHOWN);

	SDL_Event e;
	bool quitGame = false;
	while (!quitGame) {
		
		SDL_PollEvent(&e);

		switch (e.type) {

			case SDL_QUIT:
				quitGame = true;
				break;
			case SDL_MOUSEMOTION:
				std::cout << e.motion.x << " " << e.motion.y << std::endl;
				break;
			default:
				break;
		}
	}

	return 0;
}