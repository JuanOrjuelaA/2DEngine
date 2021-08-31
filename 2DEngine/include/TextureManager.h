#ifndef SDL_PROJECT_TEXTURE_MANAGER_H
#define SDL_PROJECT_TEXTURE_MANAGER_H

#include <map>
#include <SDL_render.h>
#include <string>

class TextureManager
{
public:
	bool loadImage(const std::string &fileName, const std::string &id, SDL_Renderer *pRenderer);

	void drawFrame(const std::string &id, int x, int y, int width, int height, int scaledWidth, int scaledHeight, int currentRow, int
	               currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip
	               flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_textureMap;

};


#endif // SDL_PROJECT_TEXTURE_MANAGER_H
