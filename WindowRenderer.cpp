#ifndef WINDOW_RENDERER_CPP
#define WINDOW_RENDERER_CPP

#include "include/WindowRenderer.hpp"
#include "include/Tile.hpp"
#include "include/utility.hpp"
#include "include/Player.hpp"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


WindowRenderer::WindowRenderer(char *window_name, int width, int height)
{
    this->window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_SHOWN);
    if(this->window == NULL) 
    {
        std::cout << "Error creating window: "<< SDL_GetError() << std::endl;
        SDL_Quit();
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->renderer == NULL) 
    {
        std::cout << "Error creating Renderer: "<< SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

WindowRenderer::~WindowRenderer()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
 
}

SDL_Texture * WindowRenderer::load_texture(const char * path)
{
    SDL_Texture * texture = NULL;

    texture = IMG_LoadTexture(this->renderer, path);

    if (texture == NULL)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void WindowRenderer::render_tile(Tile * tile, SDL_Rect &camera, SDL_Texture * texture)
{
    if(check_collision(tile->get_destination(),camera))
    {
        int x = tile->get_destination().x- camera.x;
        int y = tile->get_destination().y - camera.y;

        SDL_Rect renderQuad = { x, y, tile->get_destination().w, tile->get_destination().h};
        SDL_RenderCopy(this->renderer, texture, (tile->get_clip()), &(renderQuad));
    }
}

void WindowRenderer::render_player(Player &player,  SDL_Rect &camera)
{
    int x= player.get_hit_box()->x - camera.x;
    int y = player.get_hit_box()->y - camera.y;

    SDL_Rect renderQuad = { x, y , player.get_hit_box()->w , player.get_hit_box()->h };
    SDL_RenderCopy(this->renderer,player.get_texture(),&(PLAYER_CLIP_LOCATIONS[player.PLAYER_DIR]), &renderQuad);

}

void WindowRenderer::display()
{
    SDL_RenderPresent(this->renderer);
}

void WindowRenderer::clear()
{
    SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(this->renderer);
}
#endif