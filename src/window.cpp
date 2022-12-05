#include "include/window.h"

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

int Window::init()
{
	window = SDL_CreateWindow(window_name.c_str(), 100, 100, window_width, window_height, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		log_sdl_error(std::cout, "SDL_CreateWindow");
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr)
	{
		log_sdl_error(std::cout, "SDL_CreateRenderer");
		return 1;
	}

	return 0;
}

void Window::clear()
{
	SDL_RenderClear(renderer);
}

void Window::display()
{
	SDL_RenderPresent(renderer);
}
