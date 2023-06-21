#pragma once

#include "gameObject.h"

#include <SDL2/SDL.h>

class DrawableObject : public GameObject
{
public:
    DrawableObject(SDL_Renderer * renderer);
    DrawableObject(DrawableObject const&) = delete;
    virtual ~DrawableObject() = default;

    DrawableObject operator=(DrawableObject const&) = delete;

    void draw() const override = 0;
protected:
    SDL_Renderer *renderer() const;
private:
    SDL_Renderer *_renderer;
};