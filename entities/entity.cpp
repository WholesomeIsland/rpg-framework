// this file implements the functions declared in enemy.hpp and party.hpp

#include "enemy.hpp"
#include "party.hpp"
#include "inicpp.hpp"
#include "../globals/gmath.hpp"
void Enemy::Attack(Character *target, float attackLength)
{
    attacking = true;
    lastTarget = target;
    this->sprite->setAnimation("attack");
    auto& animMgr = this->sprite->animationManager;
    sf::Vector2i start = animMgr.m_startingIndicies["attack"];
    sf::Vector2i end = animMgr.m_endingIndicies["attack"];
    int frameCount = (end.x - start.x + 1) * (end.y - start.y + 1);
    this->sprite->animationManager.setAnimationFrequency("attack", frameCount / attackLength);
    this->startAtkPos = this->sprite->getPosition();
    this->attackTickDuration = attackLength;
    atkTimer.reset();
    atkTimer.start();
    std::cout << this->sprite->animationManager.m_frequencies["attack"] << " " << frameCount / attackLength << std::endl;
}
void Enemy::AttackTick(float dt)
{
    switch (mttt)
    {
    case MoveToTargetType::Straight:
        this->sprite->setPosition(lerp(startAtkPos, lastTarget->sprite->getPosition(), smoothstep(atkTimer.getElapsedTime().asSeconds() / attackTickDuration)));
        break;
    case MoveToTargetType::Jump:{
        float jumpspeed = calcJumpArcSpeed(startAtkPos, lastTarget->sprite->getPosition(), 100.0f, smoothstep(atkTimer.getElapsedTime().asSeconds() / attackTickDuration));
        this->sprite->setPosition(calculateJumpArc(startAtkPos, lastTarget->sprite->getPosition(), 100.0f, atkTimer.getElapsedTime().asSeconds() / (attackTickDuration)));
        break;
    }
    default:
        break;
    }
    if (atkTimer.getElapsedTime().asSeconds() >= attackTickDuration)
    {
        lastTarget->TakeDamage(dmgCalc(this->attack, lastTarget->defense));
        this->sprite->setAnimation("idle");
        this->sprite->animationFinishedLastFrame = false;
        attacking = false;
        atkTimer.reset();
    }
}
Enemy::Enemy(std::string spriteFile, std::string enemyDescFile, int lvl, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize)
{
    sprite = new Sprite(spriteFile);
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
Character::Character(std::string spriteFile, std::string playerini, sf::Vector2i spriteSheetSize, sf::Vector2i spriteSize)
{
    sprite = new Sprite(spriteFile);
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

void Character::TakeDamage(int damage)
{
    this->health -= damage;
    if (this->health < 0)
        this->health = 0;
}