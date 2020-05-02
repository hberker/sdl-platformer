#include <SDL2/SDL.h>
#include <iostream>

#include "include/WindowRenderer.hpp"
#include "include/Tile.hpp"
#include "include/level.hpp"

constexpr unsigned int TILES_HIGH = 20;
constexpr unsigned int TILES_WIDE = 20;

constexpr unsigned int WINDOW_WIDTH = TILE_SIZE * TILES_WIDE;
constexpr unsigned int WINDOW_HEIGHT = TILE_SIZE * TILES_HIGH;




int main(int argc, char **argv)
{
    bool game_running = true;
    SDL_Event event;
    WindowRenderer window("test",WINDOW_WIDTH,WINDOW_HEIGHT);

    SDL_Texture * rock_texture = window.load_texture("assets/rock_tile.png");

    Tile rock_tile(0,0, rock_texture);

    while(game_running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) game_running = false;
        }
        for(int i = 0; i < WINDOW_HEIGHT; i+=50)
        {
            for(int j = 0; j < WINDOW_HEIGHT; j+=50)
            {
                rock_tile = Tile(i,j, rock_texture);
                window.render(rock_tile); 
            }
        }
        
        window.display();

    }
}