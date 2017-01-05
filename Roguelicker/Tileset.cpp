#include "Tileset.h"

Tileset::~Tileset()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

Tileset::Tileset(std::string imagePath, int tileWidth, int tileHeight, SDL_Renderer* renderer)
{
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;

	SDL_Surface *loadedSurface = IMG_Load(imagePath.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load sprite texture from: " << imagePath.c_str() << ". (SDL_image Error: " << IMG_GetError() << ")" << std::endl;
	}
	else
	{
		_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		SDL_FreeSurface(loadedSurface);

		if (_texture == NULL)
		{
			std::cout << "Unable to create sprite texture from: " << imagePath.c_str() << ". (SDL_image Error: " << IMG_GetError() << ")" << std::endl;
		}
		else
		{
			SDL_QueryTexture(_texture, NULL, NULL, &_texWidth, &_texHeight);

			_tilesAcross = _texWidth / _tileWidth;
			_tilesDown = _texHeight / _tileHeight;
			_totalTiles = _tilesAcross * _tilesDown;
		}
	}
}

SDL_Rect Tileset::getRectById(int id)
{
	SDL_Rect r;
	
	r.x = (id * _tileWidth) % _texWidth;
	r.y = (id * _tileWidth / _texWidth) * _tileHeight;
	r.w = _tileWidth;
	r.h = _tileHeight;

	return r;
}

SDL_Texture* Tileset::getTexture()
{
	return _texture;
}

int Tileset::getTileWidth()
{
	return _tileWidth;
}

int Tileset::getTileHeight()
{
	return _tileHeight;
}
