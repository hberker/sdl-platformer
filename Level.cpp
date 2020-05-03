#ifndef LEVEL_CPP
#define LEVEL_CPP

#include "include/Level.hpp"

Level::Level(char * mn, int x, int y)
{
    this->map_name = mn;
    this->start_x = x;
    this->start_y = y;
}
Level::~Level()
{
    if(this->map_name != nullptr) delete this->map_name;
}

int Level::get_start_x()
{
    return this->start_x;
}
int Level::get_start_y()
{
    return this->start_y;
}
char * Level::get_map_name()
{
    return this->map_name;
}
#endif