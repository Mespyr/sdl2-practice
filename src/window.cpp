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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (window == nullptr)
	{
		log_sdl_error(std::cout, "SDL_CreateRenderer");
		return 1;
	}

	return 0;
}

SDL_Texture* Window::load_texture(std::string file_path)
{
	SDL_Texture* t = nullptr;
	t = IMG_LoadTexture(renderer, file_path.c_str());

	if (t == nullptr)
		log_sdl_error(std::cout, "IMG_LoadTexture");

	return t;
}

void Window::clear()
{
	SDL_RenderClear(renderer);
}

void Window::render(Entity& entity)
{
	SDL_Rect size;
	size.x = entity.get_current_frame().x;
	size.y = entity.get_current_frame().y;
	size.w = entity.get_current_frame().w;
	size.h = entity.get_current_frame().h;
	
	SDL_Rect pos;
	pos.x = entity.get_X() * 2;
	pos.y = entity.get_Y() * 2;
	pos.w = entity.get_current_frame().w * 2;
	pos.h = entity.get_current_frame().h * 2;

	SDL_RenderCopy(renderer, entity.get_texture(), &size, &pos);
}

void Window::display()
{
	SDL_RenderPresent(renderer);
}
