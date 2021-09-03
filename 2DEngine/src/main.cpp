#include <chrono>
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

		auto lastTime = std::chrono::system_clock::now();

		while (game->isRunning())
		{
			auto current = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsedSecs = current - lastTime;

			game->handleEvents();

			game->update(elapsedSecs.count());

			game->render();

			lastTime = current;

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