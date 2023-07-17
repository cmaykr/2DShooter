#include "sprite.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite(std::string const& texturePath, Vector2<int> const& size)
    : GameObject(), _texturePath(texturePath), _size(size)
{

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
    // Temporary
    if (!game()->resourceManager()->textureExists(_texturePath))
    {
        game()->resourceManager()->addTexture(_texturePath);
    }
    //

    SDL_Rect dsrect{};
    dsrect.h = _size.y;
    dsrect.w = _size.x;
    dsrect.x = globalPosition().x;
    dsrect.y = globalPosition().y;

    SDL_RenderCopy(game()->renderer(), game()->resourceManager()->getTexture(_texturePath), NULL, &dsrect);
}