#pragma once

#include "vector2.hpp"
#include "resourceManager.hpp"
#include "game.hpp"

#include <memory>
#include <vector>
#include <SDL2/SDL.h>

class GameObject
{
public:
    GameObject() = default;
    GameObject(GameObject const&) = delete;
    virtual ~GameObject() = default;

    /// The function initializes/sets up the gameobject.
    /// Function should be called before the gameobject is used.
    void setup(GameObject * parent, Game *game);
    
    GameObject operator=(GameObject const& rhs) = delete;

    Vector2<int> globalPosition() const;

    virtual void handleInput(SDL_Event const& event);
    virtual void fixedUpdate();
    virtual void draw() const;

    void setPosition(Vector2<int> const& position);
    void move(Vector2<int> const& positionDelta);

    template <typename Object, typename... Args>
    void addChild(Args... args);
protected:
    GameObject *parent() const;
    Game *game() const;
private:
    bool initialized{false};

    Vector2<int> _position{};
    GameObject *_parent{};

    Game *_game{};

    std::vector<std::unique_ptr<GameObject>> children{};
};

#include "gameObject.tpp"