#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Object
{
public:
	Object(int x, int y, SDL_Texture* texture) 
		: x(x), y(y), texture(texture)
	{}

	int x, y;
	SDL_Texture* texture;
	SDL_Rect current_frame;
};
