#include "include/player.h"

Player::Player(SDL_Texture* player_texture)
	: object(0, 0, player_texture)
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
	object.current_frame = right_facing_clips[0];
}

void Player::set_next_animation_frame()
{
	animation_frame_index += 1;
	if (animation_frame_index == 8) animation_frame_index = 0;

	SDL_GetMouseState(&mouse_x, &mouse_y);
	player_mouse_angle = atan2(getY() - mouse_y, getX() - mouse_x) * 180 / 3.1415;
	if ((player_mouse_angle >= 0 && player_mouse_angle <= 90) || (player_mouse_angle <= 0 && player_mouse_angle >= -90))
		object.current_frame = left_facing_clips[animation_frame_index];
	else if ((player_mouse_angle >= 90 && player_mouse_angle <= 180) || (player_mouse_angle <= 90 && player_mouse_angle >= -180))
		object.current_frame = right_facing_clips[animation_frame_index];
}

void Player::reset_animation_frame()
{
	animation_frame_index = 0;
	SDL_GetMouseState(&mouse_x, &mouse_y);
	player_mouse_angle = atan2(getY() - mouse_y, getX() - mouse_x) * 180 / 3.1415;
	if ((player_mouse_angle >= 0 && player_mouse_angle <= 90) || (player_mouse_angle <= 0 && player_mouse_angle >= -90))
		object.current_frame = left_facing_clips[animation_frame_index];
	else if ((player_mouse_angle >= 90 && player_mouse_angle <= 180) || (player_mouse_angle <= 90 && player_mouse_angle >= -180))
		object.current_frame = right_facing_clips[animation_frame_index];
}

// getters and setters and other similar stuffs
void Player::setX(int x) { object.x = x; }
void Player::setY(int y) { object.y = y; }
int Player::getX() { return object.x; }
int Player::getY() { return object.y; }
void Player::incX(int delta_x) { object.x += delta_x; };
void Player::incY(int delta_y) { object.y += delta_y; };
void Player::decX(int delta_x) { object.x -= delta_x; };
void Player::decY(int delta_y) { object.y -= delta_y; };
