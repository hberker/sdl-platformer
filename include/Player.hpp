#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL.h>

//#include "Tile.hpp"
#include "constant.hpp"

class Player
{

    public:
        Player(SDL_Texture * text);
        ~Player();

        void handle_events(SDL_Event &);
        void set_camera(SDL_Rect &);
        void move_player(class Tile ** t);
        void set_pos(int , int );
        bool at_gate(class Tile ** t);
        SDL_Texture * get_texture();
        SDL_Rect * get_hit_box();

        const int PLAYER_WIDTH = 40;
        const int PLAYER_HEIGHT= 70;
        const int PLAYER_MAX_VEL = 10;

    private:
        SDL_Rect hit_box = {0,0,PLAYER_WIDTH, PLAYER_HEIGHT};
        SDL_Texture *player_texture = NULL;
        int player_vel_x = 0;
        int player_vel_y = 0;
};

#endif