#include "include/game.h"

Game::Game(Window& window, SDL_Texture* player_texture, SDL_Texture* arm_texture, SDL_Texture* crosshair_texture)
	: window(window), player(player_texture, arm_texture), crosshair_object(0, 0, crosshair_texture)
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

void Game::update(float delta_time)
{
	// get new input and update crosshair position
	keyboard_state = SDL_GetKeyboardState(nullptr);
	SDL_GetMouseState(&mouse_position.x, &mouse_position.y);
	crosshair_object.position.x = mouse_position.x;
	crosshair_object.position.y = mouse_position.y;

		// update plater velocity
	if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_S] || keyboard_state[SDL_SCANCODE_D])
	{
		// y movement
		if (keyboard_state[SDL_SCANCODE_W])
			player.velocity.y = std::max<float>(player.velocity.y - (PLAYER_ACCEL_SPEED * delta_time), -PLAYER_MAX_SPEED);
		else if (keyboard_state[SDL_SCANCODE_S])
			player.velocity.y = std::min<float>(player.velocity.y + (PLAYER_ACCEL_SPEED * delta_time), PLAYER_MAX_SPEED);
		// if none of y movement keys are being pressed, slow down
		else if (player.velocity.y > 0)
			player.velocity.y = std::max<float>(player.velocity.y - (PLAYER_ACCEL_SPEED * delta_time), 0.0f);
		else if (player.velocity.y < 0)
			player.velocity.y = std::min<float>(player.velocity.y + (PLAYER_ACCEL_SPEED * delta_time), 0.0f);

		// x movement
		if (keyboard_state[SDL_SCANCODE_A])
			player.velocity.x = std::max<float>(player.velocity.x - (PLAYER_ACCEL_SPEED * delta_time), -PLAYER_MAX_SPEED);
		else if (keyboard_state[SDL_SCANCODE_D])
			player.velocity.x = std::min<float>(player.velocity.x + (PLAYER_ACCEL_SPEED * delta_time), PLAYER_MAX_SPEED);
		// if none of x movement keys are being pressed, slow down
		else if (player.velocity.x > 0)
			player.velocity.x = std::max<float>(player.velocity.x - (PLAYER_ACCEL_SPEED * delta_time), 0.0f);
		else if (player.velocity.x < 0)
			player.velocity.x = std::min<float>(player.velocity.x + (PLAYER_ACCEL_SPEED * delta_time), 0.0f);
	}
	else
	{
		// decrease x and y velocity since none of the movement keys are being pressed
		if (player.velocity.y > 0)
			player.velocity.y = std::max<float>(player.velocity.y - (PLAYER_ACCEL_SPEED * delta_time), 0.0f);
		else if (player.velocity.y < 0)
			player.velocity.y = std::min<float>(player.velocity.y + (PLAYER_ACCEL_SPEED * delta_time), 0.0f);
		if (player.velocity.x > 0)
			player.velocity.x = std::max<float>(player.velocity.x - (PLAYER_ACCEL_SPEED * delta_time), 0.0f);
		else if (player.velocity.x < 0)
			player.velocity.x = std::min<float>(player.velocity.x + (PLAYER_ACCEL_SPEED * delta_time), 0.0f);
	}

	// update animation if velocity is greater than 0
	if (player.velocity.x != 0 || player.velocity.y != 0)
	{
		if (player_animation_timer >= 0.12)
		{
			player.update_animation_frame(mouse_position.x, mouse_position.y, true);
			player_animation_timer = 0;
		}
		else player_animation_timer += delta_time;
	}
	else
	{
		player.update_animation_frame(mouse_position.x, mouse_position.y);
		player_animation_timer = 0;
	}

	// reposition the player
	player.update_arm_angle(mouse_position.x, mouse_position.y);
	player.update_position(delta_time);
}

void Game::render()
{
	window.clear();
	window.render(player.player_object, 4);
	window.render(player.arm_object, 4);
	window.render(crosshair_object, 3);
	window.display();
}

bool Game::running() { return !quit; }
