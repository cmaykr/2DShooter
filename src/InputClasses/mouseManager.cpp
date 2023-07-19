#include "InputClasses/mouseManager.hpp"

#include <SDL2/SDL.h>

void MouseManager::update()
{
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
}

void MouseManager::handleInput(SDL_Event *event)
{
    _leftButtonHasPressed = _leftButtonPressed;

    // Currently only checks if any mouse button is pressed.
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        _leftButtonPressed = true; 
    }
    else
    {
        _leftButtonPressed = false;
    }

}

Vector2<int> MouseManager::getMousePosition() const
{
    return mousePosition;
}

bool MouseManager::leftButtonHasPressed() const
{
    return !_leftButtonPressed && _leftButtonHasPressed;
}