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
    WindowRenderer window(GAME_NAME,WINDOW_WIDTH,WINDOW_HEIGHT);
    SDL_Texture * tile_textures = window.load_texture(TILE_TEXTURE_PATH);
    SDL_Texture * player_texture = window.load_texture(PLAYER_TEXTURE_PATH);
    SDL_Event event;

    SDL_Rect cam = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    Tile *tiles[TOTAL_TILES];
    Player player(player_texture);
    int start_frame = 0;
    int CURRENT_LEVEL = 0;
    bool game_running = true;

    Level *levels[TOTAL_LEVELS] = {
        new Level("assets/level1.map",LEVEL_WIDTH / 2,  LEVEL_HEIGHT - player.PLAYER_HEIGHT),
        new Level("assets/test.map",0,0)
    };

    //loads tiles with first level
    load_tiles(tiles, levels[0]->get_map_name());
    //Puts player at level start postion
    player.set_pos(levels[CURRENT_LEVEL]->get_start_x(), levels[CURRENT_LEVEL]->get_start_y());
    while(game_running)
    {
        window.clear();
        
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) game_running = false;
            player.handle_events(event);
        }
        
        //renderes tiles 
        for(int i = 0;  i < TOTAL_TILES; i++) window.render_tile(tiles[i], cam, tile_textures);

        player.move_player(tiles);
        player.set_camera(cam);

        if(start_frame > ANIMATION_RATE)
        {   
            player.set_next_animation();
            start_frame = 0;
        }
        start_frame++;
        
        

        window.render_player(player,cam);
        window.display();

        //Checks to see if player can progress to next level
        if(player.at_gate(tiles) && ++CURRENT_LEVEL < TOTAL_LEVELS)
        {
            load_tiles(tiles, levels[CURRENT_LEVEL]->get_map_name());
            player.set_pos(levels[CURRENT_LEVEL]->get_start_x(), levels[CURRENT_LEVEL]->get_start_y());
        }

    }
    close(tiles);
}
#endif