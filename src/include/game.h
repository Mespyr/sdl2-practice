#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Game
{
public:
	Game(const std::string &name, int width, int height) :
		window_name(name), window_width(width), window_height(height)
	{}
	~Game();

	int init();
	void log_error(std::ostream &os, const std::string &msg);

	SDL_Window* window;
	SDL_Renderer* renderer;

	const std::string window_name;
	const int window_width;
	const int window_height;
};

#endif
