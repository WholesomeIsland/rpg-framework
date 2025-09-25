#pragma once
#include "party.hpp"
enum EnemyType {
    Basic,
    Boss
};
enum MoveToTargetType {
    Straight,
    Jump
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
    Character* lastTarget;
    MoveToTargetType mttt = MoveToTargetType::Jump;
    void TakeDamage(int dmg);
    void Heal(int amt);
    void Attack(Character*, float attackLength = 1.0f);
    void AttackTick(float dt);
    Enemy(std::string spriteFile, std::string enemyDescFile, int lvl, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize);
private:
    float attackTickDuration = 10.0f; //seconds
    sf::Vector2f startAtkPos = sf::Vector2f(0.0f, 0.0f);
    sf::Clock atkTimer;
    float distAlongCurve = 0.0f;
};