#ifndef WINDOW_RENDERER_CPP
#define WINDOW_RENDERER_CPP

#include "include/WindowRenderer.hpp"
#include "include/Tile.hpp"

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
    SDL_Quit();
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


void WindowRenderer::render(Tile & tile)
{
    SDL_RenderCopy(this->renderer, tile.get_texture(), &(tile.get_size()), &(tile.get_destination()));
}
void WindowRenderer::display()
{
    SDL_RenderPresent(this->renderer);
}
#endif