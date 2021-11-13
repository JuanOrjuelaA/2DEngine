#ifndef WITZ_ENGINE_TEXTURE_MANAGER_H
#define WITZ_ENGINE_TEXTURE_MANAGER_H

#include <map>
#include <SDL_render.h>
#include <string>

#include "Singleton.h"

namespace WitzEngine
{

	class TextureManager : public Singleton<TextureManager>
	{
	public:

		bool loadImage(const std::string &fileName, const std::string &id, SDL_Renderer *pRenderer);

		void drawFrame(const std::string &id, int x, int y, int width, int height, int scaledWidth, int scaledHeight, int currentRow, 
		               int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	private:
		std::map<std::string, SDL_Texture*> m_textureMap;

	};
}

#endif
