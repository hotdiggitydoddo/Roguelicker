#pragma once

#include "Config.h"
#include "Renderer.h"
#include "Tileset.h"

class Game
{
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	Renderer* gameRenderer = NULL;
	bool is_running = false;

	//void handle_input();
	//void update();
	void draw();
	void cap_framerate(Uint32 frame_time);

public:
	~Game();
	bool init();
	void start();
};

