#include "gameObject.h"

Vector2<int> GameObject::globalPosition() const
{
    if (parent == nullptr)
        return localPosition;

    return parent->globalPosition() + localPosition;
}

void GameObject::handleInput()
{
    // TODO: Implement
}

void GameObject::fixedUpdate()
{
    // TODO: Implement
}

void GameObject::draw() const
{
    // TODO: Implement
}