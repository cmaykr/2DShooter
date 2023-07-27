#include "game.hpp"
#include "clock.hpp"
#include "GameObjects/sprite.hpp"
#include "GameObjects/player.hpp"
#include "GameObjects/camera.hpp"
#include "Serialization/deSerialization.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game(uint32_t targetFPS)
    : targetFPS(targetFPS), _window(nullptr), _renderer(nullptr), _resourceManager()
{

}

SDL_Window *Game::window() const
{
    return _window;
}

SDL_Renderer *Game::renderer() const
{
    return _renderer;
}

ResourceManager *Game::resourceManager()
{
    return &_resourceManager;
}

MouseManager *Game::mouseManager()
{
    return &_mouseManager;
}

void Game::run()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    isRunning = false;

    // TODO: Variable resolution.
    _window = SDL_CreateWindow("2DShooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);

    _renderer = SDL_CreateRenderer(_window, -1, 0);

    SDL_Event event{};
    _resourceManager.changePath("resources/");
    _resourceManager.changeRenderer(_renderer);

    double accumulatorElapsedTime{};
    Clock clock{};
    double fixedt{1000.0 / static_cast<double>(targetFPS)};

    // Sprite test
        GameObject main{};
        main.setup(nullptr, this);
        main.addChild<Sprite>("RubberDucky.png", Vector2{100, 100});
        main.setPosition(Vector2{1000, 200});
    // End Sprite test

    // Player class test
        Player player{};
        player.setup(nullptr, this);
        player.addChild<Sprite>("RubberDucky.png", Vector2{100, 100});
    //

    DeSerialization test{"testfile.txt"};
    std::cout << test.readValue<std::string>("hej") << std::endl;


    while (isRunning)
    {

        while (SDL_PollEvent(&event))
        {
            handleInput(event);

            player.handleInput(event);
            _mouseManager.handleInput(&event);
        }

        while (accumulatorElapsedTime >= fixedt)
        {
            accumulatorElapsedTime -= fixedt;
            fixedUpdate();

            player.fixedUpdate();
        }

        _mouseManager.update(); // Should this update on a fixed timeframe?
        
        SDL_RenderClear(_renderer);
        draw();
        main.draw();
        player.draw();
        
        SDL_RenderPresent(_renderer);

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
    SDL_SetRenderDrawColor(_renderer, 20, 20, 20, 0);
}