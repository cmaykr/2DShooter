#pragma once

class Game
{
public:
    Game() = default;

    void run();
private:
    bool isRunning{false};
};