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
    int attack;
    int level;
    bool doneTurn;
    bool attacking = false;
    int speed;
    Sprite* sprite;
    EnemyType type;
    Character* lastTarget = nullptr;
    void TakeDamage(int dmg);
    void Heal(int amt);
    void Attack(Character*, float attackLength = 1.0f);
    void AttackTick(float dt);
    Enemy(std::string spriteFile, std::string enemyDescFile, int lvl, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize);
};