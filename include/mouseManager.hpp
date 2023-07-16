#pragma once

#include "vector2.h"
#include "inputManager.hpp"

class MouseManager : public InputManager
{
public:
    MouseManager() = default;

    void update() override;

    Vector2<int> getMousePosition() const;
    /// @brief Checks if the left mouse button has been pressed down last update.
    bool leftButtonPressed() const; // Better name?
private:
    Vector2<int> mousePosition{};

    bool _leftButtonPressed{false}; // Better name?
    bool leftButtonPressedLastFrame{false}; // Better name?
};