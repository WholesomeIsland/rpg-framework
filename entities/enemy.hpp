struct Enemy{
    int health;
    int maxHealth;
    int magic;
    int maxMagic;
    void TakeDamage(int dmg);
    void Heal(int amt);
};