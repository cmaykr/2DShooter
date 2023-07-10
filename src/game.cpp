#include "game.h"
#include "clock.h"
#include "sprite.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game(uint32_t targetFPS)
    : targetFPS(targetFPS), window(nullptr), renderer(nullptr), resourceManager()
{

}

void Game::run()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    isRunning = true;

    // TODO: Variable resolution.
    window = SDL_CreateWindow("2DShooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);

    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event event{};
    resourceManager.changePath("resources/");
    resourceManager.changeRenderer(renderer);

    double accumulatorElapsedTime{};
    Clock clock{};
    double fixedt{1000.0 / static_cast<double>(targetFPS)};

    // Sprite test
        GameObject main{};
        main.setup(nullptr, renderer, &resourceManager);
        main.addChild<Sprite>("RubberDucky.png", Vector2{100, 100});
        main.setPosition(Vector2{1000, 200});
    // End Sprite test

    while (isRunning)
    {

        while (SDL_PollEvent(&event))
        {
            handleInput(event);
        }

        while (accumulatorElapsedTime >= fixedt)
        {
            accumulatorElapsedTime -= fixedt;
            fixedUpdate();
        }
        
        SDL_RenderClear(renderer);
        draw();
        main.draw();
        SDL_RenderPresent(renderer);

        accumulatorElapsedTime += clock.restart();
    }

    SDL_Quit();
}

void Game::handleInput(SDL_Event const& event)
{
    if (event.type == SDL_QUIT)
    {
        isRunning = false;
    }
}

void Game::fixedUpdate()
{

}

void Game::draw() const
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 0);
}