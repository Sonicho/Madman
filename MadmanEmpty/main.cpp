#include "Test.h"
#include <SDL.h>

int main(int argc, char* argv[])
{
	//Test t;
	//return t.onExecution();

	// Init SDL!
	SDL_Init( SDL_INIT_EVERYTHING );

	atexit(SDL_Quit);

	SDL_Event evtSdlEvent;
	SDL_Surface* pWindow = SDL_SetVideoMode(800, 600, 16, SDL_SWSURFACE);
	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&evtSdlEvent))
		{
			if (evtSdlEvent.type == SDL_KEYDOWN)
			{
				if (evtSdlEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				} 
				else if (evtSdlEvent.type == SDL_QUIT)
				{
					running = false;
				}
			}
		}
	}

	SDL_FreeSurface(pWindow);
	return 0;
};