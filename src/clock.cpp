#include "clock.hpp"

#include <iostream>
#include <SDL2/SDL.h>

uint32_t Clock::restart()
{
    uint32_t tempTime = startTime;
    startTime = SDL_GetTicks64();

    return SDL_GetTicks64() - tempTime;
}