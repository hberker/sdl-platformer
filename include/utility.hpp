#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <fstream>
#include <iostream>

#include "Tile.hpp"
#include "constant.hpp"

bool load_tiles(class Level *);

bool check_collision(const class SDL_Rect &, const class SDL_Rect &);

bool touches_wall(class SDL_Rect &, class Level *);
#endif 