#pragma once
#include "../entities/party.hpp"
#include "../entities/enemy.hpp"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

#ifndef ENEMY_ATTACK_ANIMATION_NAME
#define ENEMY_ATTACK_ANIMATION_NAME "attack"
#endif

struct Encounter {
    Party& player;
    std::vector<Enemy*> enemies;
    sf::Texture* bgTex;
    sf::Sprite* bgSprite;
    bool enemyTurn;
    void doTurn();
    void draw(sf::RenderWindow& window);
    Encounter(std::filesystem::path bgTexPath, Party& player, std::vector<Enemy*> enemies);
};
