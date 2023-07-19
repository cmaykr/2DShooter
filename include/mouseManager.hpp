#pragma once

#include "vector2.hpp"
#include "inputManager.hpp"

#include <SDL2/SDL.h>

class MouseManager : public InputManager
{
public:
    MouseManager() = default;

    void update() override;
    void handleInput(SDL_Event *event);

    Vector2<int> getMousePosition() const;
    /// @brief Checks if the left mouse button has been pressed down last update.
    bool leftButtonHasPressed() const; // Better name?
private:
    Vector2<int> mousePosition{};

    bool _leftButtonPressed{false}; // Better name?
    bool _leftButtonHasPressed{false};
};