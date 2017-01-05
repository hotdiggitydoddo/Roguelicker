#pragma once

#include "Config.h"

class Tileset
{
private:
	SDL_Texture* _texture;
	int _tileWidth, _tileHeight, _texWidth, _texHeight, _tilesAcross, _tilesDown, _totalTiles;

public:
	Tileset(std::string imagePath, int tileWidth, int tileHeight, SDL_Renderer* renderer);
	~Tileset();

	SDL_Rect getRectById(int id);
	SDL_Texture* getTexture();
	int getTileWidth();
	int getTileHeight();
};

