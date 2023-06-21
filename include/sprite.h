#pragma once

#include "vector2.h"
#include "drawableObject.h"

#include <string>
#include <SDL2/SDL.h>

class Sprite : public DrawableObject
{
public:
    Sprite(SDL_Renderer * renderer, std::string const& texturePath, Vector2<int> const& size);
    Sprite(Sprite const&) = delete; // TODO?: Implement

    Sprite operator=(Sprite const&) = delete; // TODO?: Implement

    std::string texturePath() const;
    Vector2<int> size() const;

    void draw() const override;
private:
    std::string _texturePath;

    Vector2<int> _size{};
    SDL_Texture *texture; // Temporary for testing.
};