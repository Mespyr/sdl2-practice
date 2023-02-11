#pragma once

#include "window.h"
#include "player.h"
#include "util.h"

class Game
{
public:
	Game(Window& window, SDL_Texture* player_texture, SDL_Texture* crosshair_texture);
	void handle_events();
	void update(Uint32 delta_time);
	void render();
	bool running();

	Window window;
	Player player;
private:
	Object crosshair_object;
	
	int player_animation_timer = 0;
	SDL_Event e;
	const Uint8* keyboard_state;
	bool quit = false;
};
