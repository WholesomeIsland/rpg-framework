#pragma once
#include "../entities/party.hpp"
#include "../entities/enemy.hpp"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>


struct Encounter {
    Party& player;
    std::vector<Enemy*> enemies;
    sf::Texture* bgTex;
    sf::Sprite* bgSprite;
    bool enemyTurn = true;
    void doTurn();
    void draw(sf::RenderWindow& window, float dt);
    Encounter(std::filesystem::path bgTexPath, Party& player, std::vector<Enemy*> enemies);
};
