#include "include/entity.h"

Entity::Entity(float x, float y, SDL_Texture* texture)
	: x(x), y(y), texture(texture)
{
	current_frame.x = 0;
	current_frame.y = 0;
	current_frame.w = 64;
	current_frame.h = 64;
}

float Entity::get_X()
{
	return x;
}

float Entity::get_Y()
{
	return y;
}

SDL_Texture* Entity::get_texture()
{
	return texture;
}

SDL_Rect Entity::get_current_frame()
{
	return current_frame;
}
