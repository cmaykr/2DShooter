#pragma once

#include "vector2.h"

#include <memory>
#include <vector>

class GameObject
{
public:
    GameObject() = default;
    ~GameObject() = default;
    
    Vector2<int> globalPosition() const;

    void handleInput();
    void fixedUpdate();
    void draw() const;
private:
    Vector2<int> localPosition{};
    GameObject *parent{};

    std::vector<std::unique_ptr<GameObject>> children{}; 
};