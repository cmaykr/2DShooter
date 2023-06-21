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
private:
    Vector2<int> _position{};
    GameObject *parent{};

    std::vector<std::unique_ptr<GameObject>> children{}; 
};