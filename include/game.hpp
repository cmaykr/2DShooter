#pragma once

#include <SDL2/SDL.h>

#include "resourceManager.hpp"
#include "mouseManager.hpp"

class Game
{
public:
    Game(uint32_t targetFPS);
    Game(Game const&) = delete;

    Game operator=(Game const&) = delete;

    /// @brief Initializes and runs the game.
    void run();
private:
    /// @brief Handles all input, e.g keyboard and mouse. 
    void handleInput(SDL_Event const&);
    /// @brief Called every 1000 / targetFPS millisecond. Use for updating game logic, e.g moving the character.
    void fixedUpdate();
    /// @brief Only draw inside this method.
    void draw() const;

    bool isRunning{false};

    uint32_t targetFPS;
    SDL_Window *window;
    SDL_Renderer *renderer;

    ResourceManager resourceManager;

};