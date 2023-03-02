#pragma once

#include "object.h"
#include <iostream>
#include <cmath>

class Player {
public:
	Player(SDL_Texture* player_texture, SDL_Texture* arm_texture);

	void setX(float x);
	void setY(float y);
	float getX();
	float getY();

	void update_animation_frame(Vec2<int> mouse_pos);
	void update_arm_angle(Vec2<int> mouse_pos);
	void update_position(double delta_time);

	Object player_object;
	Object arm_object;

	Vec2<float> velocity = {0, 0};
private:
	SDL_Rect left_clips[8];
	SDL_Rect right_clips[8];
	SDL_Rect left_arm_clip, right_arm_clip;

	int animation_frame_index = 0;
	double player_mouse_angle;
};
