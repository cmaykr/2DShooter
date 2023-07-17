#include "mouseManager.hpp"

#include <SDL2/SDL.h>

void MouseManager::update()
{
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
}

void MouseManager::handleInput(SDL_Event *event)
{
    _leftButtonPressed = false;

    // Currently only checks if any mouse button is pressed.
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        _leftButtonPressed = true; 
    }

}

Vector2<int> MouseManager::getMousePosition() const
{
    return mousePosition;
}

bool MouseManager::leftButtonPressed() const
{
    return _leftButtonPressed;
}