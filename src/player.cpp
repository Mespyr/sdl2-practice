#include "include/player.h"

Player::Player(SDL_Texture* player_texture, SDL_Texture* arm_texture)
	: player_object(0, 0, player_texture), arm_object(0, 0, arm_texture) {
	// left walking clips
	for (int i = 0; i < 8; i++) {
		left_clips[i].x = i * 16;
		left_clips[i].y = 0;
		left_clips[i].w = 16;
		left_clips[i].h = 16;
	}

	// right walking clips
	for (int i = 0; i < 8; i++) {
		right_clips[i].x = i * 16;
		right_clips[i].y = 16;
		right_clips[i].w = 16;
		right_clips[i].h = 16;
	}

	// set player default clip
	player_object.current_frame = right_clips[0];

	// setup arm clips
	left_arm_clip.x = 0;
	left_arm_clip.y = 0;
	left_arm_clip.w = 16;
	left_arm_clip.h = 16;

	right_arm_clip.x = 16;
	right_arm_clip.y = 0;
	right_arm_clip.w = 16;
	right_arm_clip.h = 16;

	// set arm default clip
	arm_object.current_frame = right_arm_clip;
}

void Player::update_animation_frame(Vec2<int> mouse_pos) {
	// change animation frame
	if (velocity.x != 0 || velocity.y != 0) {
		animation_frame_index += 1;
		if (animation_frame_index == 8) animation_frame_index = 0;
	}
	else animation_frame_index = 0;

	player_mouse_angle = atan2(getY() - mouse_pos.y, getX() - mouse_pos.x) * 180 / 3.1415;
	if ((player_mouse_angle >= 0 && player_mouse_angle <= 90) || (player_mouse_angle <= 0 && player_mouse_angle >= -90))
		player_object.current_frame = left_clips[animation_frame_index];
	else if ((player_mouse_angle >= 90 && player_mouse_angle <= 180) || (player_mouse_angle <= 90 && player_mouse_angle >= -180))
		player_object.current_frame = right_clips[animation_frame_index];
}

void Player::update_arm_angle(Vec2<int> mouse_pos) {
	player_mouse_angle = atan2(getY() - mouse_pos.y, getX() - mouse_pos.x) * 180 / 3.1415;

	if ((player_mouse_angle >= 0 && player_mouse_angle <= 90) || (player_mouse_angle <= 0 && player_mouse_angle >= -90))
		arm_object.current_frame = left_arm_clip;
	else if ((player_mouse_angle >= 90 && player_mouse_angle <= 180) || (player_mouse_angle <= 90 && player_mouse_angle >= -180))
		arm_object.current_frame = right_arm_clip;

	arm_object.angle = player_mouse_angle + 90;
}

void Player::update_position(double delta_time) {
	player_object.position += velocity * delta_time;
	arm_object.position += velocity * delta_time;
}

// getters and setters and other similar stuffs
void Player::setX(float x) {
	player_object.position.x = x;
	arm_object.position.x = x;
}
void Player::setY(float y) {
	player_object.position.y = y;
	arm_object.position.y = y;
}
float Player::getX() {
	return player_object.position.x;
}
float Player::getY() {
	return player_object.position.y;
}
