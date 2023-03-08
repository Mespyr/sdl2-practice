#include "include/util.h"
#include "include/window.h"
#include "include/game.h"

int main() {
	init_lib();
	Window window("Epic Game", 1400, 1000);
	if (window.init() != 0)
		return 1;

	SDL_Texture* player_texture = window.load_texture("assets/player.png");
	SDL_Texture* arm_texture = window.load_texture("assets/arm.png");
	SDL_Texture* crosshair_texture = window.load_texture("assets/crosshair.png");
	SDL_Texture* cobblestone_texture = window.load_texture("assets/cobblestone.png");
	Game game(window, player_texture, arm_texture, crosshair_texture, cobblestone_texture);
	game.player.setX(400);
	game.player.setY(200);

	Uint32 now, last_game_step = SDL_GetTicks();
	float delta_time;

	while (game.running()) {
		game.handle_events();
		now = SDL_GetTicks();

		// Check so we don't render for no reason, avoid having a 0 delta time
		if(last_game_step < now) {
			delta_time = (now - last_game_step) / 1000.0f;
			game.update(delta_time);
			game.render();
		}
		else SDL_Delay(1); // slow down a bit to not burn the cpu
		last_game_step = now;
	}
	
	SDL_DestroyTexture(player_texture);
	SDL_DestroyTexture(crosshair_texture);
	SDL_DestroyTexture(arm_texture);
	return 0;
}
