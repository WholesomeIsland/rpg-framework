#pragma once
#include "../entities/party.hpp"
#include "../entities/enemy.hpp"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../ui/button.hpp"

struct Encounter {
    Party& player;
    std::vector<Enemy*> enemies;
    sf::Texture* bgTex;
    sf::Sprite* bgSprite;
    bool enemyTurn = true;
    Button* fightButton;
    void doTurn();
    void draw(sf::RenderWindow& window, float dt);
    Encounter(std::filesystem::path bgTexPath, Party& player, std::vector<Enemy*> enemies, sf::Font& font);
};
