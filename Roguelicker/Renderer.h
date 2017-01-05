#pragma once

#include "Config.h"
#include "Tileset.h"

class Renderer
{
private:
	SDL_Renderer* _renderer;
	Tileset* _tileset;
public:
	Renderer(SDL_Renderer* renderer, Tileset* tileset) { _renderer = renderer; _tileset = tileset; }
	~Renderer();
	void draw(int* tileId, int x, int y);
};

