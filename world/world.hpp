#pragma once
// world class manages global game state
class World {
public:
    World() = default;
    ~World() = default;

    void update();
    void render();
};