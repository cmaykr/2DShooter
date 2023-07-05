#pragma once

#include "gameObject.h"

class Player: public GameObject
{
public:
    void handleInput() override;
    void fixedUpdate() override;
private:
};