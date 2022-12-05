#include "include/window.h"
#include "include/util.h"

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		log_sdl_error(std::cout, "SDL_Init");
		return 1;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		log_sdl_error(std::cout, "IMG_Init");
		return 1;
	}

	Window window("Epic Game", 800, 700);
	if (window.init() != 0)
		return 1;

	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}
		window.clear();
		window.display();
	}

	return 0;
}
