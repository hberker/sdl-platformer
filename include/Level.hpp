#ifndef LEVEL_HPP
#define LEVEL_HPP

class Level
{
    public:
        Level(char*,int,int);
        ~Level();
        int get_start_x();
        int get_start_y();
        char* get_map_name();



    private:
        char *map_name;
        int start_x;
        int start_y;
};


#endif