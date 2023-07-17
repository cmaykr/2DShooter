#pragma once

#include <SDL2/SDL.h>

class Clock
{
public:
    Clock() = default;

    /// @brief Restarts the clock and returns the time since last restart in milliseconds.
    /// @return Time in milliseconds.
    uint32_t restart();
private:
    uint32_t startTime{};
};