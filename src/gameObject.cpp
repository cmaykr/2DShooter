#include "gameObject.h"

#include <iostream>

GameObject::GameObject(GameObject *parent)
    : _parent(parent)
{
}

GameObject::GameObject(SDL_Renderer *renderer)
    : _renderer(renderer)
{
}

void GameObject::setup(GameObject *parent, SDL_Renderer *renderer, ResourceManager *resourceManager)
{
    if (!initialized)
    {
        _parent = parent;
        _renderer = renderer;
        _resourceManager = resourceManager;

        initialized = true;
    }
}

Vector2<int> GameObject::globalPosition() const
{
    if (_parent == nullptr)
    {
        return _position;
    }

    return _parent->globalPosition() + _position;
}

void GameObject::handleInput()
{
    // TODO: Implement
}

void GameObject::fixedUpdate()
{
    for (auto & child : children)
    {
        child->fixedUpdate();
    }
}

void GameObject::draw() const
{
    for (auto const& child : children)
    {
        child->draw();
    }
}

void GameObject::setPosition(Vector2<int> const& position)
{
    _position = position;
}

GameObject *GameObject::parent() const
{
    return _parent;
}

SDL_Renderer *GameObject::renderer() const
{
    return _renderer;
}

ResourceManager *GameObject::resourceManager() const
{
    return _resourceManager;
}
