#include "mouseManager.hpp"

#include <SDL2/SDL.h>

void MouseManager::update()
{
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

    leftButtonPressedLastFrame = _leftButtonPressed;

    // TODO: Implement checking for left mouse button press

}

Vector2<int> MouseManager::getMousePosition() const
{
    return mousePosition;
}

bool MouseManager::leftButtonPressed() const
{
    return _leftButtonPressed != leftButtonPressedLastFrame;
}