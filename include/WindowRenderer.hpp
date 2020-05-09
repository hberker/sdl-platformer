#ifndef WINDOW_RENDERER_HPP
#define WINDOW_RENDERER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Tile.hpp"
#include "Player.hpp"


class WindowRenderer
{
    public:
        WindowRenderer(const char [], int, int);
        ~WindowRenderer();

        SDL_Texture * load_texture(const char *);
        void clear();
        void render_tile(Tile *, SDL_Rect &, SDL_Texture *);
        void render_player(Player &,  SDL_Rect &);
        void display();
   
    private:
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
};


#endif