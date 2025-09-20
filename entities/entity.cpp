// this file implements the functions declared in enemy.hpp and party.hpp

#include "enemy.hpp"
#include "party.hpp"

void Enemy::Attack(Character* c){
    
}
Enemy::Enemy(std::string spriteFile, std::string enemyDescFile, int lvl){
    sprite = new Sprite(spriteFile);
    doneTurn = false;
}