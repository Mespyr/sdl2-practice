#include "include/player.h"

Player::Player(SDL_Texture* player_texture, SDL_Texture* arm_texture)
	: player_object(0, 0, player_texture), arm_object(0, 0, arm_texture)
{
	// create rectangles for left walking animation clips
	for (int i = 0; i < 8; i++)
	{
		left_facing_clips[i].x = i * 16;
		left_facing_clips[i].y = 0;
		left_facing_clips[i].w = 16;
		left_facing_clips[i].h = 16;
	}

	// create rectangles for right walking animation clips
	for (int i = 0; i < 8; i++)
	{
		right_facing_clips[i].x = i * 16;
		right_facing_clips[i].y = 16;
		right_facing_clips[i].w = 16;
		right_facing_clips[i].h = 16;
	}

	// set player default clip
	player_object.current_frame = right_facing_clips[0];

	// setup arm clips
	arm_object.current_frame.x = 0;
	arm_object.current_frame.y = 0;
	arm_object.current_frame.w = 16;
	arm_object.current_frame.h = 16;
}

void Player::update_animation_frame(int mouse_x, int mouse_y, bool moving)
{
	// change animation frame
	if (moving)
	{
		animation_frame_index += 1;
		if (animation_frame_index == 8) animation_frame_index = 0;
	}
	else animation_frame_index = 0;

	player_mouse_angle = atan2(getY() - mouse_y, getX() - mouse_x) * 180 / 3.1415;
	if ((player_mouse_angle >= 0 && player_mouse_angle <= 90) || (player_mouse_angle <= 0 && player_mouse_angle >= -90))
		player_object.current_frame = left_facing_clips[animation_frame_index];
	else if ((player_mouse_angle >= 90 && player_mouse_angle <= 180) || (player_mouse_angle <= 90 && player_mouse_angle >= -180))
		player_object.current_frame = right_facing_clips[animation_frame_index];
}

void Player::update_arm_position(int mouse_x, int mouse_y)
{
	player_mouse_angle = atan2(getY() - mouse_y, getX() - mouse_x) * 180 / 3.1415;
	arm_object.angle = player_mouse_angle + 90;
}

// getters and setters and other similar stuffs
void Player::setX(int x)
{
	player_object.x = x;
	arm_object.x = x;
}
void Player::setY(int y)
{
	player_object.y = y;
	arm_object.y = y;
}
int Player::getX() { return player_object.x; }
int Player::getY() { return player_object.y; }
void Player::incX(int delta_x)
{
	player_object.x += delta_x;
	arm_object.x += delta_x;
};
void Player::incY(int delta_y)
{
	player_object.y += delta_y;
	arm_object.y += delta_y;
};
void Player::decX(int delta_x)
{
	player_object.x -= delta_x;
	arm_object.x -= delta_x;
};
void Player::decY(int delta_y)
{
	player_object.y -= delta_y;
	arm_object.y -= delta_y;
};
