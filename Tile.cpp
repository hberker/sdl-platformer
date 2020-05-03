#ifndef TILE_CPP
#define TILE_CPP

#include "include/Tile.hpp"
#include "include/constant.hpp"

Tile::Tile(int x_pos, int y_pos, SDL_Texture *text)
{

    this->destination.x = x_pos;
    this->destination.y = y_pos;
    this->destination.w = TILE_SIZE;
    this->destination.h = TILE_SIZE;

    this->texture = text;
}
Tile::Tile(int x_pos, int y_pos ,const SDL_Rect &clip)
{
    this->clip = &clip;

    this->destination.x = x_pos;
    this->destination.y = y_pos;
    this->destination.w = TILE_SIZE;
    this->destination.h = TILE_SIZE;
}


Tile::~Tile()
{

}
SDL_Texture * Tile::get_texture()
{
    return this->texture;
}
SDL_Rect & Tile::get_destination()
{
    return this->destination;
}
const SDL_Rect * Tile::get_clip()
{
    return this->clip;
}

#endif