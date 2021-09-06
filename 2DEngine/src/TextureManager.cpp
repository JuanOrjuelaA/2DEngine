#include "include/TextureManager.h"

#include <SDL_image.h>

using namespace WitzEngine;

template<> TextureManager* 
Singleton<TextureManager>::m_instance = nullptr;

bool TextureManager::loadImage(const std::string &fileName, const std::string &id, SDL_Renderer *pRenderer)
{
	const auto pTempSurface = IMG_Load(fileName.c_str());

	if(pTempSurface == nullptr)
	{
		return false;
	}

	const auto pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if(pTexture != nullptr)
	{
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}

void TextureManager::drawFrame(const std::string &id, int x, int y, int width, int height, int scaledWidth, int scaledHeight, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width *  currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = width;
	srcRect.h = height;

	destRect.x = x;
	destRect.y = y;
	destRect.w = scaledWidth;
	destRect.h = scaledHeight;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, nullptr, flip);

}
