#include "player.h"

void Player::handleInput(SDL_Event const& event)
{

    // Temporary, input should be handled by input manager.
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_a)
        {
            rightVelocity = -1;
        }
        else if (event.key.keysym.sym == SDLK_d)    
        {
            rightVelocity = 1;
        }
    }

    if (event.type == SDL_KEYUP)
    {
        rightVelocity = 0;
    }
    //
}

void Player::fixedUpdate()
{
    Vector2<int> moveDelta {};

    moveDelta.x = speed * rightVelocity;

    move(moveDelta);
}