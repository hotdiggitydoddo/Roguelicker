#include "Renderer.h"

Renderer::~Renderer()
{
	_renderer = NULL;
	_tileset = NULL;
}

void Renderer::draw(int* tileId, int x, int y)
{
	SDL_Rect srcRect = _tileset->getRectById(*tileId);
	SDL_Rect destRect = { x, y, _tileset->getTileWidth(), _tileset->getTileHeight() };
	
	SDL_RenderCopy(_renderer, _tileset->getTexture(), &srcRect, &destRect);
}


