#ifndef UTILITY_CPP
#define UTILITY_CPP

#include "include/utility.hpp"

#include <fstream>
#include <iostream>
#include <SDL2/SDL_rect.h>

#include "include/Tile.hpp"
#include "include/constant.hpp"
#include "include/utility.hpp"


bool load_tiles(Tile * tiles[])
{
    bool success = true;
    int x = 0;
    int y = 0;

    TILE_TYPE tile_type;

    std::ifstream map("assets/test.map");
    if(map.fail()) 
    {
        std::cout << "Failed to load map\n";
        return false;
    }
    for(int i = 0; i < TOTAL_TILES; i++)
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
        tiles[i] = new Tile(x,y,CLIP_LOCATIONS[type]);
        tiles[i]->tile_type = type;
        x+= TILE_SIZE;
        if( x >= LEVEL_WIDTH )
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

void close( Tile* tiles[] )
{
    //Deallocate tiles
	for( int i = 0; i < TOTAL_TILES; ++i )
	{
		 if( tiles[ i ] != NULL )
		 {
			delete tiles[ i ];
			tiles[ i ] = NULL;
		 }
	}
    
}

bool touches_wall(SDL_Rect & rect, Tile * tiles[])
{
    //Go through the tiles
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->tile_type >= PATH_MIDDLE ) && ( tiles[ i ]->tile_type <= PATH_TOPLEFT ) )
        {
            //If the collision box touches the wall tile
            if( check_collision( rect, tiles[ i ]->get_destination() ) )
            {
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}
#endif