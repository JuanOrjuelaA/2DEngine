#ifndef WITZ_ENGINE_GAME_H
#define WITZ_ENGINE_GAME_H
#include "TextureManager.h"

namespace WitzEngine
{
	class Game
	{
	public:

		Game();

		~Game();

		void init();

		void handleEvents();

		void update(double elapsedTime);

		void render();

		void release();

		bool isRunning();

	private:
		bool is_Running;

		SDL_Renderer* m_renderer;

		SDL_Window* m_window;

	    int m_frameIndex;

		double m_heroXPosition;

		void initSDL();

		void createWindowAndRenderer();
	};
}
#endif
