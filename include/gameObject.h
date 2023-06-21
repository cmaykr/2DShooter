#pragma once

#include "vector2.h"

#include <memory>
#include <vector>

class GameObject
{
public:
    GameObject() = default;
    GameObject(GameObject * parent);
    GameObject(GameObject const&) = delete;
    virtual ~GameObject() = default;
    
    GameObject operator=(GameObject const& rhs) = delete;

    Vector2<int> globalPosition() const;

    virtual void handleInput();
    virtual void fixedUpdate();
    virtual void draw() const;

    void setPosition(Vector2<int> const& position);
    void addChild(GameObject * child);
protected:
    GameObject *parent() const;
private:
    Vector2<int> _position{};
    GameObject *_parent{};

    std::vector<GameObject*> children{}; // TODO: Use unique_ptr
};