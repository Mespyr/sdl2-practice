#include "include/game.h"

Game::Game(Window& window, SDL_Texture* player_texture, SDL_Texture* crosshair_texture)
	: window(window), player(player_texture), crosshair_object(0, 0, crosshair_texture)
{
	SDL_ShowCursor(SDL_FALSE);
	crosshair_object.current_frame.w = 16;
	crosshair_object.current_frame.h = 16;
}

void Game::display_frame()
{
	SDL_GetMouseState(&crosshair_object.x, &crosshair_object.y);
	window.clear();
	window.render(player.object, 5);
	window.render(crosshair_object, 3);
	window.display();
}
