#include "drawableObject.h"

DrawableObject::DrawableObject(SDL_Renderer *renderer)
    : GameObject(), _renderer(renderer)
{
}

SDL_Renderer *DrawableObject::renderer() const
{
    return _renderer;
}
