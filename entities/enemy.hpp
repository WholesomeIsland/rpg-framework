#pragma once
#include "party.hpp"
enum EnemyType {
    Basic,
    Boss
};

struct Enemy{
    int health;
    int maxHealth;
    int magic;
    int maxMagic;
    int defense;
    bool doneTurn;
    int speed;
    Sprite* sprite;
    EnemyType type;
    void TakeDamage(int dmg);
    void Heal(int amt);
    void Attack(Character*);
    Enemy(std::string spriteFile, std::string enemyDescFile, int lvl);
};