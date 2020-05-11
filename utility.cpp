#ifndef UTILITY_CPP
#define UTILITY_CPP

#include "include/utility.hpp"

#include <fstream>
#include <iostream>
#include <SDL2/SDL_rect.h>

#include "include/Tile.hpp"
#include "include/constant.hpp"
#include "include/utility.hpp"
#include "include/Level.hpp"


bool load_tiles(Level *level)
{
    bool success = true;
    int x = 0;
    int y = 0;
    int level_w = 0;
    int level_h = 0;

    TILE_TYPE tile_type;

    std::ifstream map(level->get_map_name());
    if(map.fail()) 
    {
        std::cout << "Failed to load map\n";
        return false;
    }
    map >> level_w >> level_h;
    int tt = level_w * level_h ;
    
    for(int i = 0; i < tt; i++)
    {
        int type = -1;
        TILE_TYPE t;
        map >> type;  
        if(map.fail()) 
        {
            std::cout << "Error loading map: Unexpected end of file!\n";
            return false;
        }
        if(type < 0 || type >= MAX_TILE)
        {
            std::cout << "Invalid map num: " << type << std::endl;
            return false;
        }
        if(level->tiles[i] != NULL) level->tiles[i] = NULL;
        level->tiles[i] = new Tile(x,y,CLIP_LOCATIONS[type]);
        level->tiles[i]->tile_type = type;
        x+= TILE_SIZE;
        if( x >= level_w * TILE_SIZE)
        {
            x = 0;
            y += TILE_SIZE;
        }
    }

    return true;

}

bool check_collision(const SDL_Rect &A, const SDL_Rect &B)
{
    if( A.y + A.h <= B.y ) return false;

    if( A.y >= B.y + B.h ) return false;

    if( A.x + A.w <= B.x ) return false;

    if( A.x >= B.x + B.w ) return false;

    return true;
}

bool touches_wall(SDL_Rect & rect, Level * level)
{
    //Go through the tiles
    for( int i = 0; i < level->get_total_tiles(); ++i )
    {
        //If the tile is a wall type tile
        if( ( level->tiles[ i ]->tile_type >= PATH_MIDDLE ) && ( level->tiles[ i ]->tile_type <= PATH_TOPLEFT ) )
        {
            //If the collision box touches the wall tile
            if( check_collision( rect, level->tiles[ i ]->get_destination() ) )
            {
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}

bool init_sdl()
{
    bool success = true;
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) != 0)
    {
        std::cout <<  "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << std::endl;
        success = false;
    }
    return success;
}

bool close()
{
    SDL_Quit();
    return true;
}
#endif