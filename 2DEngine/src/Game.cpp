#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include <include/Exceptions/SDL_Exception.h>

Game::Game()
{
	is_Running = true;
	frameIndex = 0;
}

void Game::init()
{
	initSDL();
	createWindowAndRenderer();
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Surface *surfaceTemp = IMG_Load("resources/hero_walk.png");
	heroTexture =  SDL_CreateTextureFromSurface(renderer, surfaceTemp);
	//SDL_QueryTexture(heroTexture, NULL, NULL, &sourceHeroRect.w, &sourceHeroRect.h);

	sourceHeroRect.x = frameIndex * 587;
    sourceHeroRect.y = 0;
    sourceHeroRect.w = 587;
    sourceHeroRect.h = 707;

	destHeroRect.x = 150;
    destHeroRect.y = 155;
    destHeroRect.w = 195;
    destHeroRect.h = 235;
	SDL_FreeSurface(surfaceTemp);
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
	frameIndex = int(((SDL_GetTicks() / 100) % 10));
	sourceHeroRect.x = frameIndex * 587;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopyEx(renderer, heroTexture, &sourceHeroRect, &destHeroRect, 0, NULL, SDL_FLIP_NONE );

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