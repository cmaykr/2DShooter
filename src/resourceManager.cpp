#include "resourceManager.h"

#include <SDL2/SDL_image.h>

#include <iostream>

void ResourceManager::changePath(std::string const &path)
{
    _path = path;
}

void ResourceManager::changeRenderer(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Texture *ResourceManager::getTexture(std::string const &name) const
{
    auto it = _textures.find(name);

    if (it == _textures.end())
    {
        return nullptr;
    }

    return it->second;
}

void ResourceManager::addTexture(std::string const& name)
{
    std::string filePath {};
    filePath += _path;
    filePath += name;

    _textures[name] = IMG_LoadTexture(_renderer, filePath.c_str());
}

bool ResourceManager::textureExists(std::string name) const
{
    if (_textures.find(name) != _textures.end())
        return true;

    return false;
}

std::string const &ResourceManager::path() const
{
    return _path;
}
