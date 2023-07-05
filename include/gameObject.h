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

    /// The function initializes/sets up the gameobject.
    /// Function should be called before the gameobject is used.
    void setup(GameObject * parent, SDL_Renderer * renderer);
    
    GameObject operator=(GameObject const& rhs) = delete;

    Vector2<int> globalPosition() const;

    virtual void handleInput();
    virtual void fixedUpdate();
    virtual void draw() const;

    void setPosition(Vector2<int> const& position);

    template <typename Object, typename... Args>
    void addChild(Args... args);
protected:
    GameObject *parent() const;
    SDL_Renderer *renderer() const;
private:
    bool initialized{false};

    Vector2<int> _position{};
    GameObject *_parent{};
    SDL_Renderer *_renderer{};

    std::vector<std::unique_ptr<GameObject>> children{}; // TODO: Use unique_ptr
};

#include "gameObject.tpp"