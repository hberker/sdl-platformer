#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>

#include "constant.hpp"

enum PLAYER_SPRITE_ANIMATIONS
{
    PLAYER_DOWN_LF,
    PLAYER_DOWN_BF,
    PLAYER_DOWN_RF,

    PLAYER_LEFT_LF,
    PLAYER_LEFT_BF,
    PLAYER_LEFT_RF,

    PLAYER_UP_LF,
    PLAYER_UP_BF,
    PLAYER_UP_RF,

    PLAYER_RIGHT_LF,
    PLAYER_RIGHT_BF,
    PLAYER_RIGHT_RF
};
constexpr class SDL_Rect PLAYER_CLIP_LOCATIONS[TOTAL_PLAYER_SPRITES]
{   
    //Down
    {2,0,       PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {22,0,      PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {42,0,     PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    //lEFT
    {4,28,    PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {24 ,28,    PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {46,28,     PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    //UP
    {2,56,    PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {24,56,   PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {46,56,   PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    // RIGHT
    {0,84,    PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {22,84,     PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
    {42,84,      PLAYER_SPRITE_WIDTH,PLAYER_SPRITE_HEIGHT},
};
class Player
{
    public:
        Player(class SDL_Texture * );
        ~Player();

        void handle_events(SDL_Event &);
        void set_camera(class SDL_Rect &, class Level *);
        void move_player(class  Level *);
        void set_pos(int , int );
        void set_next_animation();
        bool at_gate( class Level *);
        int get_player_direction();

        class SDL_Texture * get_texture();
        class SDL_Rect * get_hit_box();
        


        const int PLAYER_WIDTH = 40;
        const int PLAYER_HEIGHT= 70;
        const int PLAYER_MAX_VEL = 7;
        

        
    private:
        class SDL_Rect hit_box = {0,0,PLAYER_WIDTH, PLAYER_HEIGHT};
        SDL_Texture *player_texture = NULL;
        int player_vel_x = 0;
        int player_vel_y = 0;
        int PLAYER_DIR = PLAYER_UP_BF;
        bool moving = false;

};

#endif