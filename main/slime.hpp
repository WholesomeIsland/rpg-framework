#pragma once
#include "../entities/enemy.hpp"
class Slime : public Enemy {
public:
    Slime(std::string spriteFile, std::string enemyDescFile, int lvl, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize)
        : Enemy(spriteFile, enemyDescFile, lvl, spriteSheetSize, spriteSize){}
};