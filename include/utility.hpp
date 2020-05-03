#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <fstream>
#include <iostream>
#include <SDL2/SDL_rect.h>

#include "Tile.hpp"
#include "constant.hpp"

bool load_tiles(Tile ** tiles, char *);

bool check_collision(const SDL_Rect &A, const SDL_Rect &B);

void close( Tile **tiles);

bool touches_wall(SDL_Rect &, Tile **tiles);
#endif 