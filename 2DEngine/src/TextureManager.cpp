#include "..\include\TextureManager.h"

#include <SDL_image.h>



bool TextureManager::loadImage(std::string fileName, std::string id, SDL_Renderer* pRenderer)
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

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width *  currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = width;
	srcRect.h = height;

	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);

}
