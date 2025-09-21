// this file implements the functions declared in enemy.hpp and party.hpp

#include "enemy.hpp"
#include "party.hpp"
#include "inicpp.hpp"

void Enemy::Attack(Character* target){
}

Enemy::Enemy(std::string spriteFile, std::string enemyDescFile, int lvl, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize){
    sprite = new Sprite(spriteFile);
    doneTurn = false;
    std::ifstream file(enemyDescFile);
    ini::IniFile ini(file);
    this->defense = ini["stats"]["defense"].as<int>();
    this->maxHealth = ini["stats"]["maxHealth"].as<int>() + (lvl * 2);
    this->health = this->maxHealth;
    this->maxMagic = ini["stats"]["maxMagic"].as<int>();
    this->magic = this->maxMagic;
    this->speed = ini["stats"]["speed"].as<int>() + (lvl);
    this->type = static_cast<EnemyType>(ini["stats"]["type"].as<int>());
    this->attack = ini["stats"]["attack"].as<int>() + (lvl);
    this->level = lvl;
    sf::Vector2i index = sf::Vector2i(ini["animation"]["idleBeginX"].as<int>(), ini["animation"]["idleBeginY"].as<int>());
    sf::Vector2i end = sf::Vector2i(ini["animation"]["idleEndX"].as<int>(), ini["animation"]["idleEndY"].as<int>());
    this->sprite->addAnimation("idle", spriteSheetSize, spriteSize, index, 0, end);
    this->sprite->animationManager.setAnimationEndingIndex("idle", end);
    this->sprite->setAnimation("idle");
}
Character::Character(std::string spriteFile, std::string playerini, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize){
    sprite = new Sprite(spriteFile);
    doneTurn = false;
    
    std::ifstream file(playerini);
    ini::IniFile ini(file);
    this->defense = ini["stats"]["defense"].as<int>();
    this->maxHealth = ini["stats"]["maxHealth"].as<int>();
    this->health = this->maxHealth;
    this->maxMagic = ini["stats"]["maxMagic"].as<int>();
    this->magic = this->maxMagic;
    this->speed = ini["stats"]["speed"].as<int>();
    this->attack = ini["stats"]["attack"].as<int>();
    this->level = 1;
    this->sprite->addAnimation("idle", spriteSheetSize, spriteSize, sf::Vector2i(0, 0), 0, sf::Vector2i(0, 0));
    this->sprite->animationManager.setAnimationEndingIndex("idle", sf::Vector2i(ini["animation"]["idleEndX"].as<int>(), ini["animation"]["idleEndY"].as<int>()));
    this->sprite->setAnimation("idle");
}