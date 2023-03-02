#pragma once

#include "window.h"
#include "player.h"
#include "util.h"
#include "vec2.h"
#include <algorithm>

class Game {
public:
	Game(Window& window, SDL_Texture* player_texture, SDL_Texture* arm_texture, SDL_Texture* crosshair_texture);
	void handle_events();
	void update(float delta_time);
	void render();
	bool running();

	Window window;
	Player player;
private:
	Object crosshair_object;
	Vec2<int> mouse_position;
	
	float player_animation_timer = 0;
	SDL_Event e;
	const Uint8* kbd_state;
	bool quit = false;

	// constants
	const float PLAYER_MAX_SPEED = 450.0f;
	// how much player can accelerate in one second
	// multiply MAX_SPEED by n to get the acceleration needed to go full speed in 1/n of a second
	const float PLAYER_ACCEL_SPEED = PLAYER_MAX_SPEED * 5.0f;
};
