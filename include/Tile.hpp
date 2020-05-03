#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL.h>

#include "constant.hpp"

class Tile
{
    public:
        Tile(int , int , SDL_Texture *);
        Tile(int , int , const SDL_Rect &);
        ~Tile();
        SDL_Rect  & get_destination();
        const  SDL_Rect * get_clip();
        SDL_Texture * get_texture();

        int tile_type;
    private:
        SDL_Texture *texture = nullptr;
        const SDL_Rect * clip = nullptr; 
        SDL_Rect destination;
        
        
        
};

#endif