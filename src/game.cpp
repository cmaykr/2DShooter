#include "game.h"
#include <SDL2/SDL.h>

void Game::run()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    isRunning = true;

    SDL_Window *window{SDL_CreateWindow("2DShooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0)};

    SDL_Renderer *renderer{SDL_CreateRenderer(window, -1, 0)};

    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 122, 122, 122, 0);
        SDL_RenderPresent(renderer);
    }
    

    SDL_Quit();
}