#pragma once

#include "object.h"

#include <iostream>

class Player
{
public:
	Player(SDL_Texture* player_texture, SDL_Texture* arm_texture);

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	void incX(int delta_x);
	void incY(int delta_y);
	void decX(int delta_x);
	void decY(int delta_y);

	void update_animation_frame(int mouse_x, int mouse_y, bool moving = false);
	void update_arm_position(int mouse_x, int mouse_y);

	Object player_object;
	Object arm_object;
private:
	SDL_Rect left_facing_clips[8];
	SDL_Rect right_facing_clips[8];
	int animation_frame_index = 0;
	double player_mouse_angle;
};
