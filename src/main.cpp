#include "include/util.h"
#include "include/window.h"
#include "include/game.h"

int main()
{
	init_lib();

	Window window("Epic Game", 1920, 1080);
	if (window.init() != 0)
		return 1;

	SDL_Texture* player_texture = window.load_texture("assets/img/player.png");
	SDL_Texture* crosshair_texture = window.load_texture("assets/img/crosshair.png");
	Game game(window, player_texture, crosshair_texture);
	game.player.setX(500);
	game.player.setY(200);

	Uint32 minimum_fps_delta_time = (1000/6); // minimum 6 fps, if the computer is slower than this: slow down.
	Uint32 last_game_step = SDL_GetTicks(); // initial value
	Uint32 now, delta_time;

	while (game.running())
	{
		game.handle_events();
		now = SDL_GetTicks();

		// Check so we don't render for no reason, avoid having a 0 delta time
		if(last_game_step < now)
		{
			delta_time = (now - last_game_step > minimum_fps_delta_time) ? minimum_fps_delta_time : now - last_game_step;
			game.update(delta_time);
			game.render();
		}
		else SDL_Delay(1); // slow down a bit to not burn the cpu
		last_game_step = now;
	}
	
	SDL_DestroyTexture(player_texture);
	SDL_DestroyTexture(crosshair_texture);
	return 0;
}
