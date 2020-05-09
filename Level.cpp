#ifndef LEVEL_CPP
#define LEVEL_CPP

#include "include/Level.hpp"
#include "include/constant.hpp"
#include "include/Tile.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>

Level::Level(char mn[], int x, int y)
{
    this->map_name = mn ;
    this->start_x = x;
    this->start_y = y;

    std::ifstream map(map_name);
    if(map.fail()) 
    {
        std::cout << "Failed to load map\n";
    }
    map >> this->level_width >> this->level_height;
    this->total_tiles = this->level_width * this->level_height ;
    this->level_height *= TILE_SIZE;
    this->level_width *= TILE_SIZE;    
    map.close();

    //TODO SET SIZE OF TILES 
}
Level::~Level()
{
    if(this->map_name != nullptr) delete this->map_name;
    //Deallocate tiles
	for( int i = 0; i < this->total_tiles; ++i )
	{
		 if( tiles[ i ] != NULL )
		 {
			delete tiles[ i ];
			tiles[ i ] = NULL;
		 }
	}
}

int Level::get_start_x()
{
    return this->start_x;
}

int Level::get_start_y()
{
    return this->start_y;
}

int Level::get_level_h()
{
    return this->level_height;
}

int Level::get_level_w()
{
    return this->level_width;
}

int Level::get_total_tiles()
{
    return this->total_tiles;
}

char * Level::get_map_name()
{
    return this->map_name;
}
#endif