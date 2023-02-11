#include "include/game.h"

Game::Game(Window& window, SDL_Texture* player_texture, SDL_Texture* crosshair_texture)
	: window(window), player(player_texture), crosshair_object(0, 0, crosshair_texture)
{
	SDL_ShowCursor(SDL_FALSE);
	crosshair_object.current_frame.w = 16;
	crosshair_object.current_frame.h = 16;
}

void Game::handle_events()
{
	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT)
			quit = true;
}

void Game::update(Uint32 delta_time)
{
	keyboard_state = SDL_GetKeyboardState(nullptr);

	// update plater position and animation state
	if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_D])
	{
		if (keyboard_state[SDL_SCANCODE_W]) player.decY(delta_time);
		if (keyboard_state[SDL_SCANCODE_A]) player.decX(delta_time);
		if (keyboard_state[SDL_SCANCODE_S]) player.incY(delta_time);
		if (keyboard_state[SDL_SCANCODE_D]) player.incX(delta_time);

		// handle animation if player is moving
		if (player_animation_timer >= 180)
		{
			player.set_next_animation_frame();
			player_animation_timer = 0;
		}
		else player_animation_timer += delta_time;
	}
	else
	{
		player.reset_animation_frame();
		player_animation_timer = 0;
	}
}

void Game::render()
{
	SDL_GetMouseState(&crosshair_object.x, &crosshair_object.y);
	window.clear();
	window.render(player.object, 5);
	window.render(crosshair_object, 3);
	window.display();
}

bool Game::running() { return !quit; }
