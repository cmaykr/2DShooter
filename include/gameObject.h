#pragma once

#include "vector2.h"

#include <memory>
#include <vector>
#include <SDL2/SDL.h>

class GameObject
{
public:
    GameObject() = default;
    GameObject(GameObject * parent);
    GameObject(SDL_Renderer * renderer);
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
    SDL_Renderer *renderer() const;
private:
    Vector2<int> _position{};
    GameObject *_parent{};
    SDL_Renderer *_renderer{};

    std::vector<GameObject*> children{}; // TODO: Use unique_ptr
};