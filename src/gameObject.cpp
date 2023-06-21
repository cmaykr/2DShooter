#include "gameObject.h"

#include <iostream>

GameObject::GameObject(GameObject *parent)
    : _parent(parent)
{
}

Vector2<int> GameObject::globalPosition() const
{
    if (_parent == nullptr)
        return _position;

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
    std::cout << globalPosition().x << " ";
    for (auto const& child : children)
    {
        child->draw();
        std::cout << child->globalPosition().x << std::endl;
    }
}

void GameObject::setPosition(Vector2<int> const& position)
{
    _position = position;
}

void GameObject::addChild(GameObject * child)
{
    children.push_back(child);
}
