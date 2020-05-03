#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "SDL2/SDL_rect.h"

constexpr char *GAME_NAME = "GAME";
constexpr char *TILE_TEXTURE_PATH = "assets/tiles.png"; 
constexpr char *PLAYER_TEXTURE_PATH = "assets/white_ball.png";

constexpr int TILE_SIZE = 80;
constexpr int TOTAL_TILES = 192;
constexpr int TOTAL_TILE_SPRITES = 12;

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;
constexpr int LEVEL_WIDTH = 1280;
constexpr int LEVEL_HEIGHT = 960;

constexpr int TOTAL_LEVELS = 2;




constexpr SDL_Rect CLIP_LOCATIONS[TOTAL_TILE_SPRITES]
{   
    //RGB
    {0,0,       TILE_SIZE,TILE_SIZE},
    {0,80,      TILE_SIZE,TILE_SIZE},
    {0,160,     TILE_SIZE,TILE_SIZE},
    //C T TR
    {160,80,    TILE_SIZE,TILE_SIZE},
    {160 ,0,    TILE_SIZE,TILE_SIZE},
    {240,0,     TILE_SIZE,TILE_SIZE},
    //R BR B
    {240,80,    TILE_SIZE,TILE_SIZE},
    {240,160,   TILE_SIZE,TILE_SIZE},
    {160,160,   TILE_SIZE,TILE_SIZE},
    // BL L TL
    {80,160,    TILE_SIZE,TILE_SIZE},
    {80,80,     TILE_SIZE,TILE_SIZE},
    {80,0,      TILE_SIZE,TILE_SIZE},
};
enum TILE_TYPE
{
    RED_GATE_TILE = 0,
    GREEN_TILE = 1,
    BLUE_TILE = 2,

    PATH_MIDDLE = 3,
    PATH_TOP = 4,
    PATH_TOPRIGHT = 5,

    PATH_RIGHT = 6,
    PATH_BOTTOMRIGHT = 7,
    PATH_BOTTOM =  8,

    PATH_BOTTOMLEFT = 9,
    PATH_LEFT = 10,
    PATH_TOPLEFT = 11,

    MAX_TILE = 12
};
#endif