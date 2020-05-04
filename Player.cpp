#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "include/Player.hpp"
#include "include/constant.hpp"
#include "include/utility.hpp"
#include <SDL2/SDL.h>

Player::Player(SDL_Texture * text)
{
    this->player_texture = text;
}

Player::~Player()
{

}

void Player::handle_events(SDL_Event & e)
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            
            case SDLK_w: this->player_vel_y -= this->PLAYER_MAX_VEL; player_vel_x = 0; this->PLAYER_DIR = PLAYER_UP_BF; this->moving = true;break;
            case SDLK_s: this->player_vel_y += this->PLAYER_MAX_VEL; player_vel_x = 0;this->PLAYER_DIR = PLAYER_DOWN_BF; this->moving = true;break;
            case SDLK_a: this->player_vel_x -= this->PLAYER_MAX_VEL; player_vel_y = 0;this->PLAYER_DIR = PLAYER_LEFT_BF; this->moving = true;break;
            case SDLK_d: this->player_vel_x += this->PLAYER_MAX_VEL; player_vel_y = 0;this->PLAYER_DIR = PLAYER_RIGHT_BF; this->moving = true; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            
            case SDLK_w: this->player_vel_y = 0/*this->player_vel_y += this->PLAYER_MAX_VEL*/;this->moving = false; break;
            case SDLK_s: this->player_vel_y = 0/*this->player_vel_y -= this->PLAYER_MAX_VEL*/; this->moving = false;break;
            case SDLK_a: this->player_vel_x = 0/*this->player_vel_x += this->PLAYER_MAX_VEL*/; this->moving = false;break;
            case SDLK_d: this->player_vel_x = 0/*this->player_vel_x -= this->PLAYER_MAX_VEL*/; this->moving = false;break;
        }
    }


}

void Player::move_player(Tile * tiles[])
{
    // Allows players head to overlap with wall ahead of it;
    SDL_Rect adjusted_hitbox;
    int Y_offset = 30;

    this->hit_box.x += this->player_vel_x;
    adjusted_hitbox = hit_box;   
    adjusted_hitbox.y += Y_offset;
    adjusted_hitbox.h -= Y_offset;
    if((adjusted_hitbox.x  < 0) || (adjusted_hitbox.x + adjusted_hitbox.w > LEVEL_WIDTH) || touches_wall(adjusted_hitbox,tiles))
    {
        this->hit_box.x -= this->player_vel_x;
    }

    this->hit_box.y += this->player_vel_y;
    adjusted_hitbox= hit_box;
    adjusted_hitbox.y += Y_offset;
    adjusted_hitbox.h -= Y_offset;
    if((adjusted_hitbox.y  < 0) || (adjusted_hitbox.y + adjusted_hitbox.h > LEVEL_HEIGHT) || touches_wall(adjusted_hitbox,tiles))
    {
        this->hit_box.y -= this->player_vel_y;
    }
}

bool Player::at_gate(Tile * tiles[])
{
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->tile_type == RED_GATE_TILE ) )
        {
            //If the collision box touches the wall tile
            if( check_collision( this->hit_box, tiles[ i ]->get_destination() ) )
            {
                return true;
            }
        }
    }
    return false;
}

void Player::set_camera(SDL_Rect &camera)
{
    //Center the camera over the dot
	camera.x = ( this->hit_box.x + PLAYER_HEIGHT / 2 ) - WINDOW_WIDTH / 2;
	camera.y = ( this->hit_box.y + PLAYER_HEIGHT / 2 ) - WINDOW_HEIGHT / 2;

	//Keep the camera in bounds
	if( camera.x < 0 )
	{ 
		camera.x = 0;
	}
	if( camera.y < 0 )
	{
		camera.y = 0;
	}
	if( camera.x > LEVEL_WIDTH - camera.w )
	{
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if( camera.y > LEVEL_HEIGHT - camera.h )
	{
		camera.y = LEVEL_HEIGHT - camera.h;
	}
    
}

SDL_Texture *  Player::get_texture()
{
    return this->player_texture;
}

SDL_Rect * Player::get_hit_box()
{
    return &(this->hit_box);
}

void Player::set_pos(int x, int y)
{
    this->hit_box.x = x;
    this->hit_box.y = y;
}

void Player::set_next_animation()
{
    if(this->moving)
    {
        
        if(this->PLAYER_DIR <= 2)
        {
            this->PLAYER_DIR = (this->PLAYER_DIR + 1 > 2) ? this->PLAYER_DIR  - 2 : this->PLAYER_DIR + 1;

        }else if (this->PLAYER_DIR <= 5)
        {
            this->PLAYER_DIR = (this->PLAYER_DIR + 1 > 5) ? this->PLAYER_DIR  - 2 : this->PLAYER_DIR + 1;

        }else if (this->PLAYER_DIR <= 8 )
        {
            this->PLAYER_DIR = (this->PLAYER_DIR + 1 > 8) ? this->PLAYER_DIR  - 2 : this->PLAYER_DIR + 1;

        } else if(this->PLAYER_DIR <= 11)
        {
            this->PLAYER_DIR = (this->PLAYER_DIR + 1 > 11) ? this->PLAYER_DIR  - 2 : this->PLAYER_DIR + 1;
        }
    }
    
}
#endif