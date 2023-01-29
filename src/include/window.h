#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include "util.h"
#include "object.h"

class Window
{
public:
	Window(const std::string &name, int width, int height) :
		window_name(name), window_width(width), window_height(height)
	{}
	~Window();
	int init();

	SDL_Texture* load_texture(const std::string& file_path);
	void clear();
	void render(Object& obj, double scale);
	void display();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	const std::string window_name;
	const int window_width;
	const int window_height;
};
