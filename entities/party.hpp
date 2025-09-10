#pragma once
struct Character {
    int health;
    int maxHealth;
    int magic;
    int maxMagic;
    int defense;
    int level;
    bool doneTurn;
    int speed;
    void TakeDamage(int damage);
    void Heal(int amt);
};

struct Party {
    Character party[4];
};