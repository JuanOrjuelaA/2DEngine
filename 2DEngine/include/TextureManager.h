#ifndef SDL_PROJECT_TEXTURE_MANAGER_H
#define SDL_PROJECT_TEXTURE_MANAGER_H
#include <map>
#include <SDL_render.h>
#include <string>


class TextureManager
{
public:
	bool loadImage(std::string fileName, std::string id, SDL_Renderer *pRenderer);

	void drawFrame(std::string id, int x, int y, int width, int height, int scaledWidth, int scaledHeight, int currentRow, int
	               currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip
	               flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;

};


#endif // SDL_PROJECT_TEXTURE_MANAGER_H
