#include "include/util.h"

void log_sdl_error(std::ostream& os, const std::string &msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}

int init_lib()
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

	return 0;
}
