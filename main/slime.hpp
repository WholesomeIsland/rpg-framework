#pragma once
#include "../entities/enemy.hpp"
#include "SFML/System/Vector2.hpp"
class Slime : public Enemy {
public:
    sf::Clock atkTimer;
    sf::Vector2f startPos;
    sf::Vector2f endPos;
    float jumpHeight, attackDuration;
    Slime(std::string spriteFile, std::string enemyDescFile, int lvl, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize)
        : Enemy(spriteFile, enemyDescFile, lvl, spriteSheetSize, spriteSize){}
    void Attack(Character* target) override;
    void AttackTick(float dt) override;
};