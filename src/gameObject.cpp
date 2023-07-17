#include "gameObject.hpp"

#include <iostream>

void GameObject::setup(GameObject *parent, Game *game)
{
    if (!initialized)
    {
        _parent = parent;
        _game = game;


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

void GameObject::handleInput(SDL_Event const& event)
{
    // TODO: Implement?
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

void GameObject::move(Vector2<int> const &positionDelta)
{
    _position += positionDelta;
}

GameObject *GameObject::parent() const
{
    return _parent;
}

Game *GameObject::game() const
{
    return _game;
}
