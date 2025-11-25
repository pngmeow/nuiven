#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

void handleEvents(bool &running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }
}

void render(SDL_Renderer* renderer, TTF_Font* font) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    // Present renderer
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init Error: %s", SDL_GetError());
        return 1;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL initialized successfully");

    if (TTF_Init() != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_Init Error: %s", TTF_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "TTF initialized successfully");

    SDL_Window* window = SDL_CreateWindow("SDL2 TTF Example",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindow Error: %s", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window created successfully");

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Renderer created successfully");

    TTF_Font* font = TTF_OpenFont("Fixed.ttf", 24);
    if (!font) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_OpenFont Error: %s", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Font loaded successfully");

    bool running = true;
    while (running) {
        handleEvents(running);
        render(renderer, font);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}