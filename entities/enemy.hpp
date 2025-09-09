#pragma once
struct Enemy{
    int health;
    int maxHealth;
    int magic;
    int maxMagic;
    int defense;
    void TakeDamage(int dmg);
    void Heal(int amt);
};