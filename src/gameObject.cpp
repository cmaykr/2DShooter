#include "gameObject.h"

GameObject::GameObject(GameObject *parent)
    : parent(parent)
{
}

Vector2<int> GameObject::globalPosition() const
{
    if (parent == nullptr)
        return _position;

    return parent->globalPosition() + _position;
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
    // TODO: Implement
}

void GameObject::setPosition(Vector2<int> const& position)
{
    _position = position;
}
