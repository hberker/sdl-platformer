#ifndef TILE_HPP
#define TILE_HPP

#include <SDL2/SDL.h>

#include "constant.hpp"

constexpr class SDL_Rect CLIP_LOCATIONS[TOTAL_TILE_SPRITES]
{   
    //RGB
    {0,0,       TILE_SIZE,TILE_SIZE},
    {0,80,      TILE_SIZE,TILE_SIZE},
    {0,160,     TILE_SIZE,TILE_SIZE},
    //C T TR
    {160,80,    TILE_SIZE,TILE_SIZE},
    {160 ,0,    TILE_SIZE,TILE_SIZE},
    {240,0,     TILE_SIZE,TILE_SIZE},
    //R BR B
    {240,80,    TILE_SIZE,TILE_SIZE},
    {240,160,   TILE_SIZE,TILE_SIZE},
    {160,160,   TILE_SIZE,TILE_SIZE},
    // BL L TL
    {80,160,    TILE_SIZE,TILE_SIZE},
    {80,80,     TILE_SIZE,TILE_SIZE},
    {80,0,      TILE_SIZE,TILE_SIZE},
};
enum TILE_TYPE
{
    RED_GATE_TILE = 0,
    GREEN_TILE = 1,
    BLUE_TILE = 2,

    PATH_MIDDLE = 3,
    PATH_TOP = 4,
    PATH_TOPRIGHT = 5,

    PATH_RIGHT = 6,
    PATH_BOTTOMRIGHT = 7,
    PATH_BOTTOM =  8,

    PATH_BOTTOMLEFT = 9,
    PATH_LEFT = 10,
    PATH_TOPLEFT = 11,

    MAX_TILE = 12
};

class Tile
{
    public:
        Tile(int , int , SDL_Texture *);
        Tile(int , int , const class SDL_Rect &);
        ~Tile();
        SDL_Rect  & get_destination();
        const  SDL_Rect * get_clip();
        SDL_Texture * get_texture();

        int tile_type;
    private:
        SDL_Texture *texture = nullptr;
        const class SDL_Rect * clip = nullptr; 
        SDL_Rect destination;
        
        
        
};

#endif