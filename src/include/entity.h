#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
	Entity(float x, float y, SDL_Texture* texture);

	float get_X();
	float get_Y();
	SDL_Texture* get_texture();
	SDL_Rect get_current_frame();
private:
	float x, y;
	SDL_Rect current_frame;
	SDL_Texture* texture;
};
