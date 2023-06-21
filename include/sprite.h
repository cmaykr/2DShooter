#pragma once

#include "vector2.h"
#include "drawableObject.h"

#include <string>
#include <SDL2/SDL.h>

class Sprite : public DrawableObject
{
public:
    Sprite(std::string const& texturePath, Vector2<int> const& size);

    std::string texturePath() const;
    Vector2<int> size() const;
private:
    std::string _texturePath;

    Vector2<int> _size{};
};