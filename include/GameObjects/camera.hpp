#pragma once

#include "GameObjects/gameObject.hpp"
#include "vector2.hpp"

class Camera : public GameObject // Should camera inherit from gameobject?
{
public:
    Camera() = default;
    Camera(double zoom);

    /// @brief Changes the zoom of the camera.
    /// @param zoom New zoom must be higher than 0. Zoom > 0
    void changeZoom(double newZoom);

    /// @brief Converts the global position to a position on the current game window.
    /// @param globalPosition The global position of a game object.
    /// @return Window position of a gameObject.
    Vector2<int> positionToWindowPosition(Vector2<int> globalPosition) const;

private:
    double zoom{1};
};