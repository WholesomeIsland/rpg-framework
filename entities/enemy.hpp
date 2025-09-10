#pragma once

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
    EnemyType type;
    void TakeDamage(int dmg);
    void Heal(int amt);
};