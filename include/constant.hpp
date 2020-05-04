#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "SDL2/SDL_rect.h"

constexpr char *GAME_NAME = "GAME";
constexpr char *TILE_TEXTURE_PATH = "assets/tiles.png"; 
constexpr char *PLAYER_TEXTURE_PATH = "assets/pokemon_trainer.png";//"assets/person_back.png";

constexpr int TILE_SIZE = 80;
constexpr int TOTAL_TILES = 192;
constexpr int TOTAL_TILE_SPRITES = 12;
constexpr int TOTAL_PLAYER_SPRITES = 12;
constexpr int PLAYER_SPRITE_HEIGHT = 28;
constexpr int PLAYER_SPRITE_WIDTH = 17;

constexpr int ANIMATION_RATE = 6;


constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;
constexpr int LEVEL_WIDTH = 1280;
constexpr int LEVEL_HEIGHT = 960;

constexpr int TOTAL_LEVELS = 2;

#endif