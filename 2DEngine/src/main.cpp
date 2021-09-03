#include <SDL.h>
#include <cstdio>
#include "Game.h"
#include <exception>

int main(int argc, char* args[])
{
	try
	{
		auto game = new Game();
		game->init();

		while (game->isRunning())
		{
			double start = SDL_GetTicks();
			game->handleEvents();

			game->update();

			game->render();

			const int MS_PER_FRAME = 16;
			double end =  SDL_GetTicks();
			auto delay = start +  MS_PER_FRAME - end;
			if(delay > 0)
			{
				SDL_Delay(delay);
			}
			

		}

		game->release();
	}
	catch (const std::exception& ex)
	{
		fprintf(stderr, ex.what());
		SDL_Quit();
		return -1;
	}

	return 0;
}