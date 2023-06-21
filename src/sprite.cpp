#include "sprite.h"

Sprite::Sprite(std::string const& texturePath, Vector2<int> const& size)
    : _texturePath(texturePath), _size(size)
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