#ifndef MAIN_CPP
#define MAIN_CPP

#include <SDL2/SDL.h>
#include <iostream>

#include "include/constant.hpp"
#include "include/WindowRenderer.hpp"
#include "include/Tile.hpp"
#include "include/utility.hpp"
#include "include/Player.hpp"

int main(int argc, char **argv)
{
    bool game_running = true;
    SDL_Event event;
    WindowRenderer window("test",WINDOW_WIDTH,WINDOW_HEIGHT);
    SDL_Rect cam = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

    Tile *tiles[TOTAL_TILES];

    SDL_Texture * tile_textures = window.load_texture("assets/tiles.png");
    SDL_Texture * dot_texture = window.load_texture("assets/white_ball.png");

    Player player(dot_texture);
    load_tiles(tiles);

    while(game_running)
    {
        window.clear();

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) game_running = false;
            player.handle_events(event);
        }
        
        for(int i = 0;  i < TOTAL_TILES; i++)
        {
            window.render_tile(tiles[i], cam, tile_textures);
        }
        player.move_player(tiles);
        player.set_camera(cam);

        window.render_player(player,cam);
        
        window.display();

    }
    close(tiles);
}
#endif