#include "include/util.h"

void log_sdl_error(std::ostream& os, const std::string &msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}
