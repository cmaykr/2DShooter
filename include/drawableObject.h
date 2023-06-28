#pragma once

#include "gameObject.h"

#include <SDL2/SDL.h>

class DrawableObject : public GameObject
{
public:
    DrawableObject(SDL_Renderer * renderer);
    DrawableObject(DrawableObject const&) = delete;
    virtual ~DrawableObject() = default;

    void draw() const override {}
protected:
    SDL_Renderer *renderer() const;
private:
    SDL_Renderer *_renderer;
};