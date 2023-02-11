#pragma once

#include "object.h"

#include <iostream>

class Player
{
public:
	Player(SDL_Texture* player_texture);

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	void incX(int delta_x);
	void incY(int delta_y);
	void decX(int delta_x);
	void decY(int delta_y);

	void set_next_animation_frame();
	void reset_animation_frame();

	Object object;
private:
	SDL_Rect left_facing_clips[8];
	SDL_Rect right_facing_clips[8];
	int mouse_x, mouse_y;
	int animation_frame_index = 0;
	double player_mouse_angle;
};
