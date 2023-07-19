#include "GameObjects/camera.hpp"

#include <SDL2/SDL.h>
#include <iostream> // Temp

Camera::Camera(double zoom)
    : zoom(zoom)
{
}

void Camera::changeZoom(double newZoom)
{
    if (newZoom > 0.0)
    {
        zoom = newZoom;
    }

    // Throw exception here?
}

Vector2<int> Camera::positionToWindowPosition(Vector2<int> position) const
{
    Vector2<int> windowSize{};

    SDL_GetWindowSize(game()->window(), &windowSize.x, &windowSize.y);

    Vector2<int> windowPosition{};

    windowPosition = globalPosition() + position;

    std::cout << windowPosition << std::endl; // Temp

    return windowPosition;
}