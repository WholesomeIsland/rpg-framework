#pragma once
#include "party.hpp"
enum EnemyType {
    Basic,
    Boss
};
class Enemy{
    public:
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
    virtual void Attack(Character*) {}
    virtual void AttackTick(float dt) {}
    Enemy(std::string spriteFile, std::string enemyDescFile, int lvl, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize);
    ~Enemy() = default;
};