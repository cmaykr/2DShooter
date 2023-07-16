#pragma once

#include "vector2.h"
#include "gameObject.h"

#include <string>
#include <SDL2/SDL.h>

class Sprite : public GameObject
{
public:
    Sprite(std::string const& texturePath, Vector2<int> const& size);
    Sprite(Sprite const&) = delete; // TODO?: Implement

    Sprite operator=(Sprite const&) = delete; // TODO?: Implement

    std::string texturePath() const;
    Vector2<int> size() const;

    void draw() const override;
private:
    std::string _texturePath;

    Vector2<int> _size{};
};