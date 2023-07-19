#include "GameObjects/gameObject.hpp"

#include <stdexcept>

template <typename Object, typename ...Args>
void GameObject::addChild(Args... args)
{
    // INFO: Should this throw an exception? Is there a better way to handle this?
    if (!initialized)
    {
        throw std::logic_error("The gameobject needs to call setup before adding a child.");
    }

    children.push_back(std::make_unique<Object>(args...));

    auto &child = children.back();

    child->setup(this, game());
}