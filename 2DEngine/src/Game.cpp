#include <SDL.h>
#include "Game.h"
#include <include/Exceptions/SDL_Exception.h>


using namespace WitzEngine;

Game::Game()
{
	is_Running = true;
	m_frameIndex = 0;
	m_heroXPosition = 0;
}

Game::~Game()
{
}


void Game::init()
{
	initSDL();
	createWindowAndRenderer();
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	if(!TextureManager::GetInstance()->loadImage("resources/hero_walk.png", "hero", m_renderer))
	{
		throw SDL_Exception("Texture 'resources/hero_walk.png' could not be loaded");
	}
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

void Game::update(double elapsedTime)
{
	m_frameIndex = static_cast<int>((SDL_GetTicks() / 100) % 10);
	m_heroXPosition += 30 * elapsedTime;

}

void Game::render()
{
	SDL_RenderClear(m_renderer);

	TextureManager::GetInstance()->drawFrame("hero", m_heroXPosition, 155, 587, 707,195 ,235, 1, m_frameIndex, m_renderer);

	SDL_RenderPresent(m_renderer);
}

void Game::release()
{
	SDL_DestroyRenderer(m_renderer);

	SDL_DestroyWindow(m_window);

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
	SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &m_window, &m_renderer);
	if (m_window == nullptr || m_renderer == nullptr)
	{
		throw SDL_Exception(SDL_GetError());
	}
}