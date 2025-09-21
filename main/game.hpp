#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "../world/world.hpp"

class Game{
public:
    Enemy* slimeEnemyBase;
    Character* mainCharacter;
    World* mainWorld = new World();
    Game();
    void tick(sf::RenderWindow& window, float deltaTime);
};