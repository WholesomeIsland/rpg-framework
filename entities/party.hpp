struct Character {
    int health;
    int maxHealth;
    int magic;
    int maxMagic;
    int defense;
    int level;
};

struct Party {
    Character party[4];
};