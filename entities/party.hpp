#pragma once
#include "../graphics/sprite.hpp"

struct Character {
    int health;
    int maxHealth;
    int magic;
    int maxMagic;
    int defense;
    int level;
    bool doneTurn;
    int speed;
    int attack;
    Sprite* sprite;
    void TakeDamage(int damage);
    void Heal(int amt);
};

struct Party {
    Character party[4];
};