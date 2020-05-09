#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Tile.hpp"
class Level
{
    public:
        Level(char [],int,int);
        ~Level();
        int get_start_x();
        int get_start_y();
        int get_level_w();
        int get_level_h();
        int get_total_tiles();
        char* get_map_name();

        Tile *tiles[500];

    private:
        char *map_name;
        int start_x;
        int start_y;

        int level_width;
        int level_height;

        int total_tiles;
};



#endif