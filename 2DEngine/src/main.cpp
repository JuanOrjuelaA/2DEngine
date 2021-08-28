#include <SDL.h>
#include <cstdio>
#include "Game.h"
#include <exception>

int main(int argc, char* args[]) {
	try
	{
		auto game = new Game();
		game->init();

		while (game->isRunning())
		{
			game->handleEvents();

			game->update();

			game->render();
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