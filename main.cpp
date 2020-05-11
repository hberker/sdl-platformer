#ifndef MAIN_CPP
#define MAIN_CPP

#include <SDL2/SDL.h>
#include <iostream>

#include "include/constant.hpp"
#include "include/WindowRenderer.hpp"
#include "include/Tile.hpp"
#include "include/utility.hpp"
#include "include/Player.hpp"
#include "include/Level.hpp"


int main(int argc, char **argv)
{
    unsigned int start_frame = 0;
    unsigned int CURRENT_LEVEL = 0;
    bool game_running = init_sdl();;

    WindowRenderer window(GAME_NAME,WINDOW_WIDTH,WINDOW_HEIGHT);
    SDL_Texture * tile_textures = window.load_texture(TILE_TEXTURE_PATH);
    SDL_Texture * player_texture = window.load_texture(PLAYER_TEXTURE_PATH);
    SDL_Event event;
    SDL_Rect cam = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    Player player(player_texture);

    Level *levels[TOTAL_LEVELS] = 
    {
        new Level((char *) "assets/maps/level1.map",640/80  * TILE_SIZE ,850/80 * TILE_SIZE - PLAYER_SPRITE_HEIGHT),
        new Level((char *) "assets/maps/test.map",4,4),
        new Level((char *) "assets/maps/open_chamber.map", 100,100)
    };

    //loads tiles with first level
    load_tiles(levels[0]);
    //Puts player at level start postion
    player.set_pos(levels[CURRENT_LEVEL]->get_start_x(), levels[CURRENT_LEVEL]->get_start_y());
    while(game_running)
    {
        //Clear window of last frame
        window.clear();

        //Poll events for quites, moves, ability
        while(SDL_PollEvent(&event))
        {
            game_running = event.type != SDL_QUIT;
            player.handle_events(event);
        }

        //renderes tiles 
        for(int i = 0;  i < levels[CURRENT_LEVEL]->get_total_tiles(); i++) window.render_tile((levels[CURRENT_LEVEL]->tiles[i]), cam, tile_textures);
        
        //Upate player position
        player.move_player(levels[CURRENT_LEVEL]);
        //Update camera position
        player.set_camera(cam, levels[CURRENT_LEVEL]);

        //Set next frame TODO change to time based instead of frame based 
        if(start_frame > ANIMATION_RATE)
        {   
            player.set_next_animation();
            start_frame = 0;
        }
        start_frame++;

        //Checks to see if player can progress to next level
        if(CURRENT_LEVEL + 1 < TOTAL_LEVELS && player.at_gate(levels[CURRENT_LEVEL]))
        {
            CURRENT_LEVEL++;
            load_tiles(levels[CURRENT_LEVEL]);
            player.set_pos(levels[CURRENT_LEVEL]->get_start_x(), levels[CURRENT_LEVEL]->get_start_y());
        }

        //Render and display player
        window.render_player(player,cam);
        window.display();
    }
    close();
}
#endif