#include "player.hpp"

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

    if (moveDelta.x != 0)
        move(moveDelta);
    else if (game()->mouseManager()->leftButtonPressed())
    {
        setPosition(game()->mouseManager()->getMousePosition());
    }
}