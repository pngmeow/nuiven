//
// THIS IS A EXAMPLE RENDERING CODE
// Put your code in void render to test out the widgets from the NUIVEN lib
//

// Include other headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

// Include UI library headers
#include <globals.h>
#include <settings.h>
#include <ui/base.h>
#include <ui/label.h>

Label *label;

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

    // Render label
    label->render(renderer);

    // draw
    label->draw();

    // Present renderer
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    // Create and initialize label after SDL and TTF are initialized


    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_Init Error: %s", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 TTF Example",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindow Error: %s", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    gFont = TTF_OpenFont(FONT_PATH, FONT_SIZE);
    if (!gFont) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_OpenFont Error: %s", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Construct the label now that renderer and font are available
    label = new Label(0, 0, 50, 50, true, "Hello, NUIVEN!", {255, 0, 0, 255}, {0, 0, 0, 255});

    bool running = true;
    while (running) {
        handleEvents(running);
        render(renderer, gFont);
    }

    TTF_CloseFont(gFont);
    delete label;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
