#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "vec2.h"

class Object {
public:
	Object(float x, float y, SDL_Texture* texture) 
		: position(x, y), texture(texture)
	{}

	Object(Vec2<float> position, SDL_Texture* texture) 
		: position(position), texture(texture)
	{}

	Vec2<float> position;
	SDL_Texture* texture;
	SDL_Rect current_frame;
	double angle = 0;
};
