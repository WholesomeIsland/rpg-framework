// this file implements the functions declared in enemy.hpp and party.hpp

#include "enemy.hpp"
#include "party.hpp"
#include "inicpp.hpp"

void Enemy::Attack(Character* c){
    
}
Enemy::Enemy(std::string spriteFile, std::string enemyDescFile, int lvl){
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
}