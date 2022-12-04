#include "include/game.h"

int Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		log_error(std::cout, "SDL_Init");
		return 1;
	}

	window = SDL_CreateWindow(window_name.c_str(), 100, 100, window_width, window_height, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		log_error(std::cout, "SDL_CreateWindow");
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr)
	{
		log_error(std::cout, "SDL_CreateRenderer");
		return 1;
	}

	return 0;
}

Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::log_error(std::ostream& os, const std::string &msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}
