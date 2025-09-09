#pragma once
struct Character {
    int health;
    int maxHealth;
    int magic;
    int maxMagic;
    int defense;
    int level;
    void TakeDamage(int damage);
    void Heal(int amt);
};

struct Party {
    Character party[4];
};