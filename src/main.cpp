#include "include/window.h"
#include "include/util.h"
#include "include/object.h"
#include "include/game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <math.h>

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		log_sdl_error(std::cout, "SDL_Init");
		return 1;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		log_sdl_error(std::cout, "IMG_Init");
		return 1;
	}

	if (TTF_Init() != 0)
	{
		log_sdl_error(std::cout, "TTF_Init");
		return 1;
	}

	Window window("Epic Game", 1920, 1200);
	if (window.init() != 0)
		return 1;

	SDL_Texture* player_texture = window.load_texture("res/img/player.png");
	SDL_Texture* crosshair_texture = window.load_texture("res/img/crosshair.png");
	Game game(window, player_texture, crosshair_texture);
	game.player.setX(200);
	game.player.setY(200);

	SDL_Event e;
	bool quit = false;
	const Uint8* keyboard_state;
	int space_count = 0;

	while (!quit)
	{
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				quit = true;

		keyboard_state = SDL_GetKeyboardState(nullptr);
		if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_D])
		{
			if (keyboard_state[SDL_SCANCODE_W]) game.player.decY(6);
			if (keyboard_state[SDL_SCANCODE_A]) game.player.decX(6);
			if (keyboard_state[SDL_SCANCODE_S]) game.player.incY(6);
			if (keyboard_state[SDL_SCANCODE_D]) game.player.incX(6);

			// handle animation if player is moving
			if (space_count == 20)
			{
				game.player.set_next_animation_frame();
				space_count = 0;
			}
			else space_count ++;
		}
		else
		{
			game.player.reset_animation_frame();
			space_count = 0;
		}
		game.display_frame();
	}

	return 0;
}
