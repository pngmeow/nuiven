#ifndef SETTINGS_H
#define SETTINGS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define FONT_SIZE 24

// Variables
extern const char* FONT_PATH;

// Variables [SDL Pointers]
extern TTF_Font* gFont;

#endif