#include "Game.h"

void Game::draw()
{
	//clear screen
	SDL_RenderClear(renderer);
	//drawing here
	int tileId = 51;
	gameRenderer->draw(&tileId, 100, 100);
	//update screen
	SDL_RenderPresent(renderer);
}

void Game::cap_framerate(Uint32 frame_time)
{
	if ((1000 / FPS) > SDL_GetTicks() - frame_time)
	{
		SDL_Delay(1000 / FPS - (SDL_GetTicks() - frame_time));
	}
}

Game::~Game()
{
	delete(gameRenderer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Game::init()
{
	//init sdl with desired functionality
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize!  SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		//create the window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			return false;
		}

		//create the renderer
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
				return false;
			}

			//init renderer and png loading
			else
			{
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

				//init png functionality
				if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
				{
					std::cout << "SDL_image could not be initialized! SDL_Image_Error: " << IMG_GetError() << std::endl;
					return false;
				}
			}
			
			Tileset* t = new Tileset("./resources/tiles.png", 16, 16, renderer);
			gameRenderer = new Renderer(renderer, t);
		}
		return true;
	}
}

void Game::start()
{
	is_running = true;
	SDL_Event event;

	while (is_running)
	{
		Uint32 frame_time = SDL_GetTicks();

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				is_running = false;
		}

		//handle_input();
		//update();
		draw();

		cap_framerate(frame_time);
	}
}
