#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

void log_sdl_error(std::ostream& os, const std::string &msg);
int init_lib();
