#ifndef SDL_PROJECT_GAME_H
#define SDL_PROJECT_GAME_H

class Game
{
public:
	
	Game();
	
	void init();

	void handleEvents();

	void update();

	void render();

	void release();

	bool isRunning();
	
private:
	bool is_Running;

	SDL_Renderer *renderer;

	SDL_Window *window;

	void initSDL();

	void createWindowAndRenderer();
};


#endif // SDL_PROJECT_GAME_H


