#include "sprite.h"

#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite(SDL_Renderer * renderer, std::string const& texturePath, Vector2<int> const& size)
    : GameObject(renderer), _texturePath(texturePath), _size(size), texture()
{
    texture = IMG_LoadTexture(renderer, _texturePath.c_str());
}

std::string Sprite::texturePath() const
{
    return _texturePath;
}

Vector2<int> Sprite::size() const
{
    return _size;
}

void Sprite::draw() const
{
    SDL_Rect dsrect{};
    dsrect.h = _size.y;
    dsrect.w = _size.x;
    dsrect.x = globalPosition().x;
    dsrect.y = globalPosition().y;

    SDL_RenderCopy(renderer(), texture, NULL, &dsrect);
}