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

SDL_Texture* Window::load_texture(const std::string& file_path)
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

void Window::render(Object& obj, double scale)
{
	SDL_Rect size;
	size.x = obj.current_frame.x;
	size.y = obj.current_frame.y;
	size.w = obj.current_frame.w;
	size.h = obj.current_frame.h;
	
	SDL_Rect pos;
	pos.x = obj.x - size.w;
	pos.y = obj.y - size.h;
	pos.w = obj.current_frame.w * scale;
	pos.h = obj.current_frame.h * scale;

	SDL_RenderCopy(renderer, obj.texture, &size, &pos);
}

void Window::change_window_color(int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderClear(renderer);
}

void Window::display()
{
	SDL_RenderPresent(renderer);
}
