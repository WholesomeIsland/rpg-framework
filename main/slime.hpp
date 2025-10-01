#pragma once
#include "../entities/enemy.hpp"
#include "SFML/System/Vector2.hpp"
class Slime : public Enemy {
public:
    sf::Clock atkTimer;
    sf::Vector2f startPos;
    sf::Vector2f endPos;
    float jumpHeight, attackDuration;
    Slime(int lvl);
    void Attack(Character* target) override;
    void AttackTick(float dt) override;
};