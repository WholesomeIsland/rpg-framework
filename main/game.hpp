#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "../world/world.hpp"
#include "slime.hpp"

class Game{
public:
    Slime* slimeEnemyBase;
    Character* mainCharacter;
    World* mainWorld = new World();
    Game();
    void tick(sf::RenderWindow& window, float deltaTime);
};