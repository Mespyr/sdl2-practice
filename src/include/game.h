#pragma once

#include "window.h"
#include "player.h"
#include "util.h"

class Game
{
public:
	Game(Window& window, SDL_Texture* player_texture, SDL_Texture* crosshair_texture);
	void display_frame();

	Window window;
	Player player;
private:
	Object crosshair_object;
};
