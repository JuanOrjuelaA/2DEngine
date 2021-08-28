#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include <include/Exceptions/SDL_Exception.h>

Game::Game()
{
	is_Running = true;
}

void Game::init()
{
	initSDL();
	createWindowAndRenderer();

	IMG_Load("");
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			is_Running = false;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::release()
{
	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);

	SDL_Quit();
}

bool Game::isRunning()
{
	return is_Running;
}

void Game::initSDL()
{
	auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

	if (!isInitialized) {
		throw SDL_Exception(SDL_GetError());
	}
}

void Game::createWindowAndRenderer()
{
	SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &window, &renderer);
	if (window == NULL || renderer == NULL)
	{
		throw SDL_Exception(SDL_GetError());
	}
}