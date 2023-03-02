#include "include/window.h"

Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

int Window::init() {
	window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		log_sdl_error(std::cout, "SDL_CreateWindow");
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr) {
		log_sdl_error(std::cout, "SDL_CreateRenderer");
		return 1;
	}

	return 0;
}

SDL_Texture* Window::load_texture(const std::string& file_path) {
	SDL_Texture* t = nullptr;
	t = IMG_LoadTexture(renderer, file_path.c_str());
	if (t == nullptr)
		log_sdl_error(std::cout, "IMG_LoadTexture");
	return t;
}

void Window::clear() {
	SDL_RenderClear(renderer);
}

void Window::render(Object& obj, double scale) {
	SDL_Rect pos;
	pos.x = obj.position.x - obj.current_frame.w;
	pos.y = obj.position.y - obj.current_frame.h;
	pos.w = obj.current_frame.w * scale;
	pos.h = obj.current_frame.h * scale;

	SDL_RenderCopyEx(renderer, obj.texture, &obj.current_frame, &pos, obj.angle, nullptr, SDL_FLIP_NONE);
}

void Window::display() {
	SDL_RenderPresent(renderer);
}
