#pragma once

class InputManager
{
public:
    InputManager() = default;
    virtual ~InputManager() = default;

    virtual void update() = 0;
};