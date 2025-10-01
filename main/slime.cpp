#include "slime.hpp"
#include "../globals/gmath.hpp"


Slime::Slime(int lvl)
        : Enemy::Enemy("enemy/slime.png", "enemy/slime.ini", lvl, sf::Vector2i(14, 0), sf::Vector2i(32, 32)){}

void Slime::Attack(Character* target) {
    // Initialize animation parameters
    startPos = sprite->getPosition();
    endPos = target->sprite->getPosition(); 
    jumpHeight = 50.0f; 
    attackDuration = 1.0f;
    attacking = true;
    atkTimer.restart();
}


void Slime::AttackTick(float dt) {
    if (attacking) {
        // Update animation and calculate position based on jump arc
        float t = atkTimer.getElapsedTime().asSeconds() / attackDuration;
        sf::Vector2f pos = calculateJumpArc(startPos, endPos, jumpHeight, t);
        sprite->setPosition(pos);

        if (t >= 1.0f) {
            attacking = false;
            atkTimer.restart();
        } else {
        }
    }
}