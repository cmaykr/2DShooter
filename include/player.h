#pragma once

#include "gameObject.h"
#include "vector2.h"

class Player: public GameObject
{
public:
    void handleInput(SDL_Event const& event) override;
    void fixedUpdate() override;
private:
    double rightVelocity{}; // Temporary for testing.

    double speed{10}; // Temporary constant.
};